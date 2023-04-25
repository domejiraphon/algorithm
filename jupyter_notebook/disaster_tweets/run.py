import pandas as pd
import os
import sys
import numpy as np
from tqdm import tqdm
import argparse 
from loguru import logger 
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn import svm
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.decomposition import TruncatedSVD
from sklearn.linear_model import SGDClassifier
import scipy.sparse as sp
from gensim.test.utils import common_texts
from gensim.models import KeyedVectors
import seaborn as sns
import matplotlib.pyplot as plt 
import re 

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

class Covid19Dataset:
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
    
    
    self.text = self.dataset['text'].tolist()
    self.location = self.dataset['location'].tolist()
    self.keyword = self.dataset['keyword'].tolist()
    self.labels = self.dataset['target'].tolist()
    
  def __load_dataset(self, path, val_size):
    path_to_file = os.path.join(args.path_to_dataset, path)
    dataset = pd.read_csv(path_to_file)
    
    dataset = self.__clean(dataset)
    train_dataset, val_dataset = train_test_split(dataset, 
                                                  test_size=val_size, 
                                                  random_state=args.random)
    return train_dataset, val_dataset

  def __clean(self, df):
    
    if 'target' in df.columns:
      df.dropna(subset=['target', 'text'], inplace=True)
    
    df.drop_duplicates(keep="first")
    df['text'] = df['text'].apply(lambda x : str(x).lower())
    return df
  
class Model:
  def __init__(self):
    if args.model == "gb":
      self.classifier = GradientBoostingClassifier(
          n_estimators=500, max_depth=10, learning_rate=0.1, min_samples_split=10)
    elif args.model == "svm":
      self.classifier = svm.SVC(kernel='rbf')
    elif args.model == "rf":
      self.classifier = RandomForestClassifier(n_estimators=100, max_depth=5, random_state=42)
    elif args.model == "sgd":
      self.classifier = SGDClassifier()
    else:
        raise "Model not supported"
    if args.word2vec:
      self.word_vectors = KeyedVectors.load_word2vec_format('../covid19_classification/GoogleNews-vectors-negative300.bin', binary=True)
    else:
      self.vectorizer = TfidfVectorizer()
      self.vectorizer_concat = TfidfVectorizer()
  def train(self, train_dataset):
    if args.word2vec:
      out = self.__get_vectors(train_dataset.text, 
                               train_dataset.location,
                               train_dataset.keyword)
    else:
      out = self.vectorizer.fit_transform(train_dataset.text)
  
    self.classifier.fit(out, train_dataset.labels)
   
  def predict(self, test_dataset):
    if args.word2vec:
      out = self.__get_vectors(test_dataset.text, 
                               test_dataset.location,
                               test_dataset.keyword)
    else:
      out = self.vectorizer.transform(test_dataset.text)
    
   
    return self.classifier.predict(out)

  def __get_vectors__(self, text, location, keyword):
    vectors = []
    for sentence in text:
      vector = np.zeros(300)
      
      for word in sentence.split():
        if word in self.word_vectors:
          vector += self.word_vectors[word]
        
      vectors.append(vector)

    vectors = np.stack(vectors, 0)
    if args.concat_loc:
      loc_vectors = []
      for loc in location:
        vector = np.zeros(300)
        for word in sentence.split():
          word = re.sub('[^a-zA-Z]', '', word)
          if word in self.word_vectors:
            vector += self.word_vectors[word]
        loc_vectors.append(vector)
      loc_vectors = np.stack(loc_vectors, 0)

      vectors = np.concatenate([vectors, loc_vectors], 1)
    if args.concat_keyword:
      key_vectors = []
      for loc in keyword:
        vector = np.zeros(300)
        for word in sentence.split():
          word = re.sub('[^a-zA-Z]', '', word)
          if word in self.word_vectors:
            vector += self.word_vectors[word]
        key_vectors.append(vector)
      key_vectors = np.stack(key_vectors, 0)
      #vectors += key_vectors
      vectors = np.concatenate([vectors, key_vectors], 1)
   
    return vectors

def compute_accuracy(y_val, y_pred, str1):
  accuracy = sum([1 for i in range(len(y_val)) if y_val[i] == y_pred[i]]) / len(y_val)
  print(f"{str1} accuracy: {accuracy}")

def infer(model, val_loader, str1="val"):
  y_val = val_loader.labels
  y_pred = model.predict(val_loader)
  compute_accuracy(y_val, y_pred, str1)

@logger.catch
def main():
  train_dataset = Covid19Dataset(data_type="train")
  val_dataset = Covid19Dataset(data_type="val")
  #test_dataset = Covid19Dataset(data_type="test")
  
  #model = Model()
  model = bert()
  #model.trainBatch(train_dataset)
  model.train(train_dataset)
  infer(model, train_dataset, "Train")
  infer(model, val_dataset, "Val")
  #infer(model, test_dataset, "Test")
    
if __name__ == "__main__":
  main()
