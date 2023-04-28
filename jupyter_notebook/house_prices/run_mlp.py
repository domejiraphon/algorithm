import pandas as pd
import os
import sys
import numpy as np
import argparse
from loguru import logger
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn import svm
from sklearn.ensemble import GradientBoostingClassifier, GradientBoostingRegressor, RandomForestClassifier, RandomForestRegressor
import matplotlib.pyplot as plt
import seaborn as sns
import torch
from torch.utils.data import Dataset, DataLoader
import torch.nn as nn

parser = argparse.ArgumentParser()
parser.add_argument('--path_to_dataset', type=str, default="./dataset")
parser.add_argument('--model', type=str, choices=['svm', 'gb', 'rf', 'sgd'], default='svm')
parser.add_argument('--random', type=int, default=0)
parser.add_argument('--concat_loc', action='store_true')
parser.add_argument('--concat_keyword', action='store_true')
parser.add_argument('--word2vec', action='store_true')
parser.add_argument('--num_classes', type=int, default=3)
parser.add_argument('--hidden_size', type=int, default=128)
parser.add_argument('--batch_size', type=int, default=256)
parser.add_argument('--num_epochs', type=int, default=5)
parser.add_argument('--num_hidden', type=int, default=1)
parser.add_argument('--val_size', type=float, default=0.2)
parser.add_argument('--lr', type=float, default=0.1)
args = parser.parse_args()

class HouseDataset(Dataset):
  mean = None 
  std = None
  fillna_mean = None 
  def __init__(self, data_type="train"):
    if data_type == "train":
      self.dataset, _ = self.__load_dataset("train.csv", 
                                            args.val_size)

    elif data_type == "val":
      _, self.dataset = self.__load_dataset("train.csv", 
                                            args.val_size)
    else:
      self.dataset, _ = self.__load_dataset("test.csv", 
                                            1e-3)
    self.features = self.__get_features()
    
    if HouseDataset.mean is None:
      HouseDataset.mean, HouseDataset.std = self.__calculate_normalization_params(
                               self.features)
   
    self.__normalize_features()
    
    self.labels = torch.from_numpy(self.features[:, -1:]).float()
    self.features = torch.from_numpy(self.features[:, :-1]).float()
    
    
  def __len__(self):
    return len(self.features)

  def __getitem__(self, idx):
    return {"features": self.features[idx],
            "labels": self.labels[idx]}

  def __load_dataset(self, path, val_size):
    path_to_file = os.path.join(args.path_to_dataset, path)
    dataset = pd.read_csv(path_to_file)

    dataset = self.__clean(dataset)
    train_dataset, val_dataset = train_test_split(dataset, test_size=val_size, random_state=args.random)
    return train_dataset, val_dataset

  def __clean(self, df):
    df = df.drop_duplicates(keep="first")
    df = df.drop('Id', axis=1)

    df = self.__handling_missing_data(df)

    for column in df.columns:
      if df[column].dtype == 'object':
        df[column] = pd.factorize(df[column])[0]

    return df

  def __handling_missing_data(self, df):
    numeric_cols = df.select_dtypes(include=np.number).columns

    if HouseDataset.fillna_mean is None:
      HouseDataset.fillna_mean = df[numeric_cols].mean()

    df[numeric_cols] = df[numeric_cols].fillna(HouseDataset.fillna_mean)
    categorical_cols = df.select_dtypes(exclude=np.number).columns
    df[categorical_cols] = df[categorical_cols].fillna('Unknown')
    return df 

  def __get_features(self):
    features = []
    for column in self.dataset.columns:
      features.append(self.dataset[column].tolist())
    return np.stack(features, axis=1)

  def __normalize_features(self):
    self.features = (self.features - HouseDataset.mean) / (HouseDataset.std + 1e-9)

  @staticmethod
  def __calculate_normalization_params(features):
    mean = np.mean(features, 0, keepdims=True)
    std = np.std(features, 0, keepdims=True)
    return mean, std
class Model(nn.Module):
  def __init__(self, 
               input_size, 
               output_size=1):
    super(Model, self).__init__()
    model = [nn.Linear(input_size, args.hidden_size),
             nn.ReLU()]
    for _ in range(args.num_hidden):
      model.append(nn.Linear(args.hidden_size, 
                             args.hidden_size))
      model.append(nn.Dropout(0.3))
      model.append(nn.ReLU())
    model.append(nn.Linear(args.hidden_size, output_size))
  
    self.model = nn.Sequential(*model)
      
  def forward(self, x):
    return self.model(x)
  
  def train(self, 
            train_loader, 
            optimizer, 
            device):
    self.model.train()
    
    for epoch in range(args.num_epochs):
      train_loss = 0
      for features in train_loader:
        optimizer.zero_grad()
        inputs = features['features'].to(device)
        labels = features['labels'].to(device)
        
        outputs = self.model(inputs)
        loss = torch.mean((outputs - labels) ** 2)
        loss.backward()
        optimizer.step()
        train_loss += loss.item()
      train_loss /= len(train_loader)
      print(f"Epoch: {epoch}, Train loss: {round(train_loss, 4)}")

  def predict(self, dataloader, device):
    self.model.eval()
    predictions = []
    loss = 0
    with torch.no_grad():
      for features in dataloader:
        inputs = features['features'].to(device)
        labels = features['labels'].to(device)
        outputs = self.model(inputs)
        
        loss += torch.mean((outputs - labels) ** 2)
        
        pred_with_labels = list(zip(outputs.cpu().numpy().flatten() * HouseDataset.std[0, -1] + HouseDataset.mean[0, -1], 
                                    labels.cpu().numpy().flatten() * HouseDataset.std[0, -1] + HouseDataset.mean[0, -1]))
        predictions.extend(pred_with_labels)
      
    return predictions, loss/ len(dataloader)

def infer(model, val_loader, device, str1="val"):
  y_pred, loss = model.predict(val_loader, device)
  print(y_pred[0:6])
  print(f"{str1} MSE Loss: {loss}, Approx: {np.sqrt(loss)}")
 
@logger.catch
def main():
  train_dataset = HouseDataset(data_type="train")
  val_dataset = HouseDataset(data_type="val")
  #test_dataset = HouseDataset(data_type="test")
  
  model = Model(input_size=train_dataset.features.shape[1])
  optimizer = torch.optim.Adam(model.parameters(), 
                    lr=args.lr)
  train_dataloader = DataLoader(train_dataset, 
                              batch_size=args.batch_size, 
                              shuffle=True)
  val_dataloader = DataLoader(val_dataset, 
                            batch_size=args.batch_size, 
                            shuffle=False)
  device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
  model.train(train_dataloader, optimizer, device)
  infer(model, train_dataloader, device, "Train")
  infer(model, val_dataloader, device, "Val")
  #infer(model, test_dataset, device, "Test")
    
if __name__ == "__main__":
  main()
