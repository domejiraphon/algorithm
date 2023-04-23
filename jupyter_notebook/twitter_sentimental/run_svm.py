import pandas as pd
import os
import sys
from tqdm import tqdm
import argparse 
from loguru import logger 
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn import svm
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.ensemble import RandomForestClassifier

parser = argparse.ArgumentParser()
parser.add_argument('--path_to_dataset', type=str, default="./dataset")
parser.add_argument('--model', type=str, choices=['svm', 'gb', 'rf'], default='svm')
parser.add_argument('--random', type=int, default=0)
parser.add_argument('--num_classes', type=int, default=3)
parser.add_argument('--val_size', type=float, default=0.2)
args = parser.parse_args()


class SentimentDataset:
  def __init__(self, train=True):
    if train:
      self.dataset, _ = self.__load_dataset("train.csv")
    else:
      self.dataset, _ = self.__load_dataset("test.csv")
    
    self.label_map = {'negative': 0, 'neutral': 1, 'positive': 2}
    self.text = self.dataset['text'].tolist()
    self.labels = self.dataset['sentiment'].apply(lambda x: self.label_map[x]).tolist()
   
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
  
class Model:
  def __init__(self):
    if args.model == "gb":
      self.classifier = GradientBoostingClassifier(
        n_estimators=500, max_depth=10, learning_rate=0.1, min_samples_split=10)
    elif args.model == "svm":
      self.classifier = svm.SVC(kernel='linear')
    elif args.model == "rf":
      self.classifier = RandomForestClassifier(n_estimators=100, max_depth=10, random_state=42)
    else:
      raise "Model not supported"
    self.vectorizer = TfidfVectorizer()

  def train(self, X_train, y_train):
    self.classifier.fit(self.vectorizer.fit_transform(X_train), y_train)
    return self.classifier.predict(self.vectorizer.transform(X_train))

  def predict(self, X_test):
    return self.classifier.predict(self.vectorizer.transform(X_test))

def compute_accuracy(y_val, y_pred, str1):
  accuracy = sum([1 for i in range(len(y_val)) if y_val[i] == y_pred[i]]) / len(y_val)
  print(f"{str1} accuracy: {accuracy}")

def infer(model, val_loader, str1="val"):
  X_val = val_loader.text
  y_val = val_loader.labels
  y_pred = model.predict(X_val)
  compute_accuracy(y_val, y_pred, str1)

@logger.catch
def main():
  train_dataset = SentimentDataset(train=True)
  val_dataset = SentimentDataset(train=True)
  test_dataset = SentimentDataset(train=False)
 
  model = Model()
  y_pred = model.train(train_dataset.text, train_dataset.labels)
  compute_accuracy(train_dataset.labels, y_pred, "Train")

  infer(model, val_dataset, "Val")
  infer(model, test_dataset, "Test")
    
if __name__ == "__main__":
  main()
