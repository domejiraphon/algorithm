import pandas as pd
import os
import sys
import numpy as np
import argparse 
from loguru import logger 
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn import svm
from sklearn.ensemble import GradientBoostingClassifier,\
                             GradientBoostingRegressor, \
                             RandomForestClassifier,\
                             RandomForestRegressor
import matplotlib.pyplot as plt 
import seaborn as sns
parser = argparse.ArgumentParser()
parser.add_argument('--path_to_dataset', type=str, default="./dataset")
parser.add_argument('--model', type=str, choices=['svm', 'gb', 'rf', 'sgd'], default='svm')
parser.add_argument('--random', type=int, default=0)
parser.add_argument('--concat_loc', action='store_true')
parser.add_argument('--concat_keyword', action='store_true')
parser.add_argument('--word2vec', action='store_true')
parser.add_argument('--num_classes', type=int, default=3)
parser.add_argument('--val_size', type=float, default=0.2)
args = parser.parse_args()

class HouseDataset:
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
    self.features = []
    for column in self.dataset.columns:
      if column != 'SalePrice':
        self.features.append(self.dataset[column].tolist())
    self.features = np.stack(self.features, 1)
    #if data_type == "train":
    #  HouseDataset.mean, HouseDataset.std = self.__calculate_normalization_params(
    #                          self.features)
    
    #self.__normalized()
    if data_type != "test":
      self.labels = self.dataset['SalePrice'].tolist()
    
  def __load_dataset(self, path, val_size):
    path_to_file = os.path.join(args.path_to_dataset, path)
    dataset = pd.read_csv(path_to_file)
    
    dataset = self.__clean(dataset)
    train_dataset, val_dataset = train_test_split(dataset, 
                                                  test_size=val_size, 
                                                  random_state=args.random)
    return train_dataset, val_dataset

  def __clean(self, df):
    df = df.drop_duplicates(keep="first")
    df = df.drop('Id', axis=1)
    #df.dropna(axis=1, how="any", inplace=True)
    df = self.__handling_missing_data(df)
    for column in df.columns:
      if df[column].dtype == 'object':
        df[column] = pd.factorize(df[column])[0]
    
    return df

  def plot(self, df):
    plt.figure(figsize=(10, 7))
    sns.distplot(df['SalePrice'], 
                 color='b', 
                 bins=100, 
                 hist_kws={'alpha': 0.4})
    plt.savefig("./1.jpg")
  
  @staticmethod
  def __calculate_normalization_params(features):
    mean = np.mean(features, 0, keepdims=True)
    std = np.std(features, 0, keepdims=True)
    return mean, std
  
  def __normalized(self):
    self.features = (self.features - HouseDataset.mean) / HouseDataset.std

  def __handling_missing_data(self, df):
    numeric_cols = df.select_dtypes(include=np.number).columns

    if HouseDataset.fillna_mean is None:
      HouseDataset.fillna_mean = df[numeric_cols].mean()

    df[numeric_cols] = df[numeric_cols].fillna(HouseDataset.fillna_mean)
    categorical_cols = df.select_dtypes(exclude=np.number).columns
    df[categorical_cols] = df[categorical_cols].fillna('Unknown')
    return df 

class Model:
  def __init__(self):
    if args.model == "gb":
      self.classifier = GradientBoostingRegressor(
                              loss='squared_error',
                              n_estimators=500, 
                              max_depth=2, 
                              learning_rate=0.1, 
                              min_samples_split=10)
    elif args.model == "svm":
      self.classifier = svm.SVR(kernel='rbf')
    elif args.model == "rf":
      self.classifier = RandomForestRegressor(n_estimators=100, 
                                              max_depth=20, 
                                              random_state=0)
    else:
        raise "Model not supported"
    
  def train(self, train_dataset):
    self.classifier.fit(train_dataset.features, train_dataset.labels)
    
  def predict(self, test_dataset):
    return self.classifier.predict(test_dataset.features)

def compute_accuracy(y_val, y_pred, str1):
  y_val = np.array(y_val)
  err = np.mean((y_val - y_pred) **2)
  print(f"{str1} MSE Loss: {err}, Approx: {np.sqrt(err)}")

def infer(model, val_loader, str1="val"):
  y_pred = model.predict(val_loader)
  print(y_pred[0:6])
  
  if str1.lower() != "test":
    y_val = val_loader.labels
    
    
    print('\n')
    print(y_val[0:6])
    
    compute_accuracy(y_val, y_pred, str1)

@logger.catch
def main():
  train_dataset = HouseDataset(data_type="train")
  val_dataset = HouseDataset(data_type="val")
  test_dataset = HouseDataset(data_type="test")
  
  model = Model()
  
  model.train(train_dataset)
  infer(model, train_dataset, "Train")
  infer(model, val_dataset, "Val")
  infer(model, test_dataset, "Test")
    
if __name__ == "__main__":
  main()
