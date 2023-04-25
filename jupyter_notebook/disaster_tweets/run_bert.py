import torch
import torch.nn as nn
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from transformers import BertTokenizer, BertModel
from torch.utils.data import DataLoader
from torch.optim import Adam
from loguru import logger 

class BertClassifier(nn.Module):
  def __init__(self, num_classes):
    super(BertClassifier, self).__init__()
    self.bert = BertModel.from_pretrained('bert-base-uncased')
    self.fc = nn.Linear(768, num_classes)

  def forward(self, 
              input_ids,
              attention_mask):
    
    outputs = self.bert(input_ids, attention_mask)
    out = self.fc(outputs.pooler_output)
    return out
  
class Covid19Dataset:
  def __init__(self, path, val_size, data_type="train"):
    df = self.__clean(path)
    train_df, val_df = train_test_split(df, test_size=0.2, random_state=42)
    if data_type == "train":
      df = train_df
    else:
      df = val_df
    self.texts = df['text'].apply(lambda x : str(x).lower()).tolist()
    self.labels = df['target'].astype(int).tolist()
    self.tokenizer = BertTokenizer.from_pretrained('bert-base-uncased')
    self.val_size = val_size

  def __len__(self):
    return len(self.texts)

  def __getitem__(self, idx):
    inputs = self.tokenizer.encode_plus(self.texts[idx], 
                                        add_special_tokens=True, 
                                        return_tensors='pt')
   
    return {'input_ids': inputs['input_ids'][0],
            'attention_mask': inputs['attention_mask'][0],
            'labels': torch.tensor(self.labels[idx])}
  
  def __clean(self, path):
    df = pd.read_csv(path)
    df.dropna(subset=['target', 'text'], inplace=True)
    df.drop_duplicates(keep="first", inplace=True)
    return df

  def collate_fn(self, batch):
    input_ids = [item['input_ids'] for item in batch]
    attention_mask = [item['attention_mask'] for item in batch]
    labels = [item['labels'] for item in batch]
    max_len = max(len(ids) for ids in input_ids)
    input_ids_padded = torch.stack([torch.cat((ids, 
                                               torch.zeros(max_len - len(ids), dtype=torch.long))) for ids in input_ids])
    attention_mask_padded = torch.stack([torch.cat((mask, 
                                                    torch.zeros(max_len - len(mask), dtype=torch.long))) for mask in attention_mask])
    labels_tensor = torch.tensor(labels)
    return {'input_ids': input_ids_padded,
            'attention_mask': attention_mask_padded,
            'labels': labels_tensor} 

def train(model, train_loader, optimizer, criterion, device):
  model.train()
  train_loss = 0
  for _, features in enumerate(train_loader):
    optimizer.zero_grad()
    input_ids = features['input_ids'].to(device)
    attention_mask = features['attention_mask'].to(device)
    labels = features['labels'].to(device)
    
    outputs = model(input_ids, attention_mask)
    loss = criterion(outputs, labels)
    loss.backward()
    optimizer.step()
    print(f"Train loss: {loss}")
    train_loss += loss.item()
  train_loss /= len(train_loader)
         
# Define the validation function
def validate(model, val_loader, criterion, device):
  model.eval()
  val_loss = 0
  with torch.no_grad():
    for features in val_loader:
      input_ids = features['input_ids'].to(device)
      attention_mask = features['attention_mask'].to(device)
      labels = features['labels'].to(device)
      outputs = model(input_ids, attention_mask)
      loss = criterion(outputs, labels)
      val_loss += loss.item()
    val_loss /= len(val_loader)
    print(f"Validation loss: {val_loss}")

def evaluate(model, data_loader, device):
  model.eval()
  total_correct = 0
  with torch.no_grad():
    for _, features in enumerate(data_loader):
      input_ids = features['input_ids'].to(device)
      attention_mask = features['attention_mask'].to(device)
      labels = features['labels'].to(device)
      outputs = model(input_ids, attention_mask)
      _, predicted = torch.max(outputs, dim=1)
      total_correct += (predicted == labels).sum().item()
  accuracy = total_correct / len(data_loader.dataset)
  print(f"Accuracy: {accuracy}")

@logger.catch
def main():
  # Set device
  device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
  
  # Define hyperparameters
  batch_size = 16
  learning_rate = 2e-5
  num_epochs = 3
  num_classes = 2
  # Define dataset and dataloaders
  train_dataset = Covid19Dataset(path="./dataset/train.csv", 
                           val_size=0.2,
                           data_type="train")
  val_dataset = Covid19Dataset(path="./dataset/train.csv", 
                           val_size=0.2,
                           data_type="val")
  # Define model, optimizer and loss function
  model = BertClassifier(num_classes).to(device)
  optimizer = Adam(model.parameters(), 
                    lr=learning_rate)
  loss_fn = nn.CrossEntropyLoss()

  # Define dataloaders
  train_dataloader = DataLoader(train_dataset, 
                              batch_size=batch_size, 
                              shuffle=True,
                              collate_fn=train_dataset.collate_fn)
  val_dataloader = DataLoader(val_dataset, 
                            batch_size=batch_size, 
                            shuffle=False,
                            collate_fn=val_dataset.collate_fn)
  evaluate(model, val_dataloader, device)
  # Train the model
  for epoch in range(num_epochs):
    print(f"Epoch {epoch+1}/{num_epochs}")
    train(model, train_dataloader, optimizer, loss_fn, device)
      

if __name__ == "__main__":
  main()
