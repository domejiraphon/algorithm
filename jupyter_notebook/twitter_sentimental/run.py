import pandas as pd
import os
import sys
import torch
import matplotlib.pyplot as plt 
import seaborn as sb
from tqdm import tqdm
import argparse 
from loguru import logger 
from sklearn.model_selection import train_test_split
import torch
import torch.nn as nn
from torch.utils.data import Dataset
from transformers import RobertaTokenizer, RobertaModel

parser = argparse.ArgumentParser()
parser.add_argument('--path_to_dataset', type=str, default="./dataset")
parser.add_argument('--random', type=int, default=0)
parser.add_argument('--num_classes', type=int, default=3)
parser.add_argument('--batch_size', type=int, default=2)
parser.add_argument('--hidden_layers', type=int, default=768)
parser.add_argument('--val_size', type=float, default=0.2)
args = parser.parse_args()


class SentimentDataset(Dataset):
  def __init__(self, train=True):
    if train:
      self.dataset, _ = self.__load_dataset("train.csv")
    else:
      self.dataset, _ = self.__load_dataset("test.csv")
    
    self.tokenizer = RobertaTokenizer.from_pretrained('roberta-base',add_prefix_space=True)
    self.label_map = {'negative': 0, 'neutral': 1, 'positive': 2}

  def __len__(self):
    return len(self.dataset)

  def __getitem__(self, index):
    row = self.dataset.iloc[index]
    
    text = str(row['text']).lower()
    sentiment = self.label_map[row['sentiment']]
    encoding = self.tokenizer(text, truncation=True, padding=True)
    input_ids = encoding['input_ids']
    attention_mask = encoding['attention_mask']
    return {
        'input_ids': torch.tensor(input_ids, dtype=torch.long),
        'attention_mask': torch.tensor(attention_mask, dtype=torch.long),
        'labels': torch.tensor(sentiment, dtype=torch.long)
    }

  def __load_dataset(self, path):
    path_to_file = os.path.join(args.path_to_dataset, path)
    dataset = pd.read_csv(path_to_file)
    dataset = self.__clean(dataset)
    train_dataset, val_dataset = train_test_split(dataset, test_size=args.val_size, random_state=args.random)
    return train_dataset, val_dataset

  def __clean(self, df):
    df.dropna(axis=0, how="any", inplace=True)
    df.drop_duplicates(keep="first")
    df['text'] = df['text'].apply(lambda x : str(x).lower())
    if 'selected_text' in df.columns:
      df['selected_text'] = df['selected_text'].apply(lambda x : str(x).lower())
    return df
  
  def collate_fn(self, batch):
    max_len = max([len(seq['input_ids']) for seq in batch])
    padded_inputs = torch.zeros((len(batch), max_len), dtype=torch.long)
    padded_attention_masks = torch.zeros((len(batch), max_len), dtype=torch.long)
    padded_labels = torch.zeros((len(batch)), dtype=torch.long)

    for i, seq in enumerate(batch):
      length = len(seq['input_ids'])
      padded_inputs[i, :length] = torch.tensor(seq['input_ids'])
      padded_attention_masks[i, :length] = torch.tensor(seq['attention_mask'])
      padded_labels[i] = torch.tensor(seq['labels'])

    return {'input_ids': padded_inputs, 
            'attention_mask': padded_attention_masks, 
            'labels': padded_labels}

class Model(nn.Module):
  def __init__(self):
    super(Model, self).__init__()
    self.model = RobertaModel.from_pretrained('roberta-base')
    self.dropout = nn.Dropout(0.1)
    self.mlp = nn.Linear(args.hidden_layers, args.num_classes)

  def forward(self, input_ids, attention_mask):
    outputs = self.model(input_ids=input_ids, 
                        attention_mask=attention_mask)
    pooled_output = outputs[1]
    pooled_output = self.dropout(pooled_output)
    logits = self.mlp(pooled_output)
    return logits

def train_model(model, train_loader, val_loader, criterion, optimizer, device, num_epochs=5):
  train_losses = []
  val_losses = []
  for epoch in range(num_epochs):
    model.train()
    train_loss = 0.0
    for batch in train_loader:
      input_ids = batch['input_ids'].to(device)
      attention_mask = batch['attention_mask'].to(device)
      labels = batch['labels'].to(device)
      
      optimizer.zero_grad()
      outputs = model(input_ids=input_ids, attention_mask=attention_mask)
      loss = criterion(outputs, labels)
      loss.backward()
      optimizer.step()
      train_loss += loss.item() * input_ids.size(0)
    train_loss /= len(train_loader.dataset)
    train_losses.append(train_loss)
    model.eval()
    val_loss = 0.0
    with torch.no_grad():
      for batch in tqdm(val_loader):
        input_ids = batch['input_ids'].to(device)
        attention_mask = batch['attention_mask'].to(device)
        labels = batch['labels'].to(device)
        outputs = model(input_ids=input_ids, attention_mask=attention_mask)
        loss = criterion(outputs, labels)
        val_loss += loss.item() * input_ids.size(0)
    val_loss /= len(val_loader.dataset)
    val_losses.append(val_loss)

    print(f"Epoch {epoch+1}/{num_epochs}, Train Loss: {train_loss:.4f}, Val Loss: {val_loss:.4f}")

  plt.plot(train_losses, label='Train Loss')
  plt.plot(val_losses, label='Val Loss')
  plt.legend()
  plt.show()

@logger.catch
def main():
  train_dataset = SentimentDataset(train=True)
  val_dataset = SentimentDataset(train=True)
  test_dataset = SentimentDataset(train=False)
  train_loader = torch.utils.data.DataLoader(train_dataset, 
                                            batch_size=args.batch_size, 
                                            shuffle=True,
                                            collate_fn=train_dataset.collate_fn)
  val_loader = torch.utils.data.DataLoader(val_dataset, 
                                            batch_size=args.batch_size, 
                                            shuffle=True,
                                            collate_fn=val_dataset.collate_fn)
  test_loader = torch.utils.data.DataLoader(test_dataset, 
                                            batch_size=args.batch_size, 
                                            shuffle=True,
                                            collate_fn=test_dataset.collate_fn)
  
  device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
  model = Model().to(device)
  criterion = nn.CrossEntropyLoss()
  optimizer = torch.optim.Adam(model.parameters())

  train_model(model, 
              train_loader, 
              val_loader, 
              criterion, 
              optimizer, 
              device, 
              num_epochs=5)
    
if __name__ == "__main__":
  main()
