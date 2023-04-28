import pandas as pd
import os
import sys
import xgboost as xgb
import sklearn
from sklearn.inspection import plot_partial_dependence
import numpy as np
import argparse 
from loguru import logger 
from sklearn.model_selection import train_test_split, cross_val_score, KFold
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn import svm
from sklearn.ensemble import GradientBoostingClassifier,\
                             GradientBoostingRegressor, \
                             RandomForestClassifier,\
                             RandomForestRegressor
from sklearn.linear_model import Ridge
import matplotlib.pyplot as plt 
import seaborn as sns
parser = argparse.ArgumentParser()
parser.add_argument('--path_to_dataset', type=str, default="./dataset")
parser.add_argument('--model', type=str, choices=['svm', 'gb', 'rf', 'xgb', 'ridge'], default='gb')
parser.add_argument('--random', type=int, default=0)
parser.add_argument('--drop', action='store_true')
parser.add_argument('--word2vec', action='store_true')
parser.add_argument('--kfold', type=int, default=5)
args = parser.parse_args()

class ConcreteDataset:
  def __init__(self, data_type="train"):
    if data_type == "train":
      self.dataset = self.__load_dataset("train.csv")
    else:
      self.dataset = self.__load_dataset("test.csv")
    self.df = self.dataset
    self.features = []
    
    for column in self.dataset.columns:
      if column != 'Strength':
        self.features.append(self.dataset[column].tolist())
    self.features = np.stack(self.features, 1)
   
    if data_type != "test":
      self.labels = np.array(self.dataset['Strength'].tolist())
    
  def __load_dataset(self, path):
    path_to_file = os.path.join(args.path_to_dataset, path)
    dataset = pd.read_csv(path_to_file)
    
    dataset = self.__clean(dataset)
    return dataset

  def __clean(self, df):
    df = df.drop_duplicates(keep="first")
    if args.drop:
      df = df.drop(['id', 'FlyAshComponent', 
                  'BlastFurnaceSlag', 'SuperplasticizerComponent',
                  ], axis=1)
    else:
      df = df.drop(['id'], axis=1)
    df.dropna(axis=1, how="any", inplace=True)
    df['AgeInDays'] = df['AgeInDays'].clip(upper=40)
    df['WaterComponent'] = df['WaterComponent'].clip(upper=200)
    return df

class Model:
  def __init__(self, model):
    if model == "gb":
      self.classifier = GradientBoostingRegressor(
                              loss='squared_error',
                              n_estimators=500, 
                              max_depth=3, 
                              learning_rate=0.1, 
                              min_samples_split=10,
                              subsample=1.0)
    elif model == "xgb":
      self.classifier = xgb.XGBRegressor(
          objective='reg:squarederror',
          n_estimators=500,
          max_depth=3,
          learning_rate=0.01,
          subsample=1.0
      )
    elif model == "svm":
      self.classifier = svm.SVR(kernel='rbf')
    elif model == "rf":
      self.classifier = RandomForestRegressor(n_estimators=100, 
                                              max_depth=10, 
                                              random_state=0)
    elif model == "ridge":
      self.classifier = Ridge(0.7)
    else:
        raise "Model not supported"
    
  def train(self, features, labels):
    self.classifier.fit(features, labels)
    
  def predict(self, features):
    return self.classifier.predict(features)
  
  def plot_importance(self, feature_names):
    importance_scores = self.classifier.feature_importances_
    
    sorted_indices = np.argsort(importance_scores)[::-1]
    sorted_scores = importance_scores[sorted_indices]
    sorted_feature_names = feature_names[sorted_indices]

    # Plot the feature importance scores
    plt.figure(figsize=(10, 6))
    plt.bar(range(len(sorted_scores)), sorted_scores, tick_label=sorted_feature_names)
    plt.xticks(rotation=90)
    plt.xlabel('Features')
    plt.ylabel('Importance Scores')
    plt.title('Feature Importance Scores')
    plt.show()
  
  def plot_partial_dependency(self, train_dataset):
    feature_names = train_dataset.df.columns.tolist()
  
    fig, ax = plt.subplots(figsize=(8, 8))
   
    plot_partial_dependence(self.classifier, train_dataset.features,
                                range(0, len(feature_names) - 1), 
                                feature_names=feature_names, 
                                ax=ax)
    plt.tight_layout()
    plt.show()

class Ensemble:
  def __init__(self):
    models_used = ["xgb", "ridge", "rf"]
    self.model = [Model(m) for m in models_used]
    self.weights = [0.5, 0.3, 0.2]
  def train(self, features, labels):
    for m in self.model:
      m.train(features, labels)
    
  def predict(self, features):
    out = 0
    for w, m in zip(self.weights, self.model):
      out += w * m.predict(features)
    return out
    
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
  train_dataset = ConcreteDataset(data_type="train")
  test_dataset = ConcreteDataset(data_type="test")
  
  #model = Model()
  model = Ensemble()
  kfold = KFold(n_splits=args.kfold, 
                random_state=args.random, 
                shuffle=True)
  avg_t_loss = 0
  avg_v_loss = 0
  for fold, (train_indices, val_indices) in enumerate(kfold.split(train_dataset.features)):
    train_features = train_dataset.features[train_indices.astype(int)]
    train_labels  = train_dataset.labels[train_indices.astype(int)]
    val_features = train_dataset.features[val_indices.astype(int)]
    val_labels = train_dataset.labels[val_indices.astype(int)]

    model.train(train_features, train_labels)
    t_loss = np.sqrt(np.mean((train_labels - model.predict(train_features)) **2))
    v_loss = np.sqrt(np.mean((val_labels - model.predict(val_features)) **2))
    avg_t_loss += t_loss
    avg_v_loss += v_loss
    print(f"Fold {fold}: Train mse = {t_loss:.3f} Val mse = {v_loss:.3f}")
  print(f"Avg train mse = {avg_t_loss/args.kfold:.3f}   rmse = {avg_v_loss/args.kfold:.3f}")
  #model.plot_partial_dependency(train_dataset)
  #test_predictions = model.predict(test_dataset.features)
  #print("Test Predictions:", test_predictions)

if __name__ == "__main__":
  main()
