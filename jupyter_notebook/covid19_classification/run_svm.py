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

parser = argparse.ArgumentParser()
parser.add_argument('--path_to_dataset', type=str, default="./dataset")
parser.add_argument('--model', type=str, choices=['svm', 'gb', 'rf', 'sgd'], default='svm')
parser.add_argument('--random', type=int, default=0)
parser.add_argument('--concat', action='store_true')
parser.add_argument('--word2vec', action='store_true')
parser.add_argument('--num_classes', type=int, default=3)
parser.add_argument('--val_size', type=float, default=0.2)
args = parser.parse_args()


class Covid19Dataset:
  def __init__(self, data_type="train"):
    if data_type == "train":
      self.dataset, _ = self.__load_dataset("training_data.csv", 
                                            args.val_size)
    elif data_type == "val":
      _, self.dataset = self.__load_dataset("training_data.csv",
                                            args.val_size)
    else:
      raise "Not supported"
      self.dataset, _ = self.__load_dataset("test_data.csv",
                                            1e-3)
     
    self.label_map = {'us': 0, 
                      'uk': 1, 
                      'canada': 2, 
                      'australia': 3,
                      'ireland': 4,
                      'new_zealand': 5}
   
    self.text = self.dataset['text'].tolist()
    
    self.is_quote = self.dataset['is_quote'].apply(lambda x: 1 if x == "true" else 0).tolist()
    self.is_retweet = self.dataset['is_retweet'].apply(lambda x: 1 if x == "true" else 0).tolist()
    self.hashtags = self.dataset['hashtags'].tolist()
    
    self.labels = self.dataset['country'].apply(lambda x: self.label_map[x]).tolist()

  def __load_dataset(self, path, val_size):
    path_to_file = os.path.join(args.path_to_dataset, path)
    dataset = pd.read_csv(path_to_file)
    
    dataset = self.__clean(dataset)
    train_dataset, val_dataset = train_test_split(dataset, 
                                                  test_size=val_size, 
                                                  random_state=args.random)
    return train_dataset, val_dataset

  def __clean(self, df):
    df = df.drop('reply_to_screen_name', axis=1)
    df.dropna(axis=0, how="any", inplace=True)
    df.drop_duplicates(keep="first")
    df['text'] = df['text'].apply(lambda x : str(x).lower())
    df['is_retweet'] = df['is_retweet'].apply(lambda x : str(x).lower())
    df['is_quote'] = df['is_quote'].apply(lambda x : str(x).lower())
    df['hashtags'] = df['hashtags'].apply(lambda x : str(x).lower())
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
    elif args.model == "sgd":
      self.classifier = SGDClassifier()
    else:
        raise "Model not supported"
    if args.word2vec:
      self.word_vectors = KeyedVectors.load_word2vec_format('./GoogleNews-vectors-negative300.bin', binary=True)
    else:
      self.vectorizer = TfidfVectorizer()
      self.vectorizer_concat = TfidfVectorizer()
  def train(self, train_dataset):
    if args.word2vec:
      out = self.__get_vectors(train_dataset.text)
    else:
      out = self.vectorizer.fit_transform(train_dataset.text)
  
    self.classifier.fit(out, train_dataset.labels)
    
  def trainBatch(self, train_dataset, batch_size=1000, n_epochs=10):
    X_train = train_dataset.text
    y_train = train_dataset.labels
    n_samples = len(X_train)
    if not args.word2vec:
      out = self.vectorizer.fit(train_dataset.text)
    if args.concat:
      self.vectorizer_concat.fit(train_dataset.hashtags)
    indices = np.arange(len(X_train)).astype(int)
    for epoch in range(n_epochs):
      np.random.shuffle(indices) 
      for i in range(0, n_samples, batch_size):
        batch_indices = indices[i:i+batch_size]
        X_batch = [X_train[idx] for idx in batch_indices]
        y_batch = [y_train[idx] for idx in batch_indices]
        if args.word2vec:
          out = self.__get_vectors(X_batch)
        else:
          out = self.vectorizer.transform(X_batch)
        
        if args.concat:
          # add additional features to TF-IDF vectors
          features1 = sp.csr_matrix([train_dataset.is_retweet[idx] for idx in batch_indices]).T
          features2 = sp.csr_matrix([train_dataset.is_quote[idx] for idx in batch_indices]).T
          hashtags = np.array([train_dataset.hashtags[idx] for idx in batch_indices])
          
          # create binary feature vector indicating presence of hashtag
          #vectorizer2 = TfidfVectorizer(vocabulary=train_dataset.hashtags)
          hashtag_features = self.vectorizer_concat.transform(hashtags)
          #hashtag_features = sp.csr_matrix(np.array(np.sum(hashtag_features, axis=1) > 0)[:, None])
          
          #hashtag_features = np.array(np.sum(hashtag_features, axis=1) > 0)[:, None]
          
          out_concat = sp.hstack([out, features1, features2, hashtag_features])
          out = out_concat.tocsr()
        print(f"Epoch: {epoch}, i: {i}")
       
        self.classifier.partial_fit(out, y_batch, classes=np.unique(y_train))

  def predict(self, test_dataset):
    if args.word2vec:
      out = self.__get_vectors(test_dataset.text)
    else:
      out = self.vectorizer.transform(test_dataset.text)
    
    if args.concat:
      # add additional features to TF-IDF vectors
     
      features1 = sp.csr_matrix(test_dataset.is_retweet).T
      features2 = sp.csr_matrix(test_dataset.is_quote).T
      #hashtags = np.array([train_dataset.hashtags[idx] for idx in batch_indices])
      
      # create binary feature vector indicating presence of hashtag
      #vectorizer2 = TfidfVectorizer(vocabulary=train_dataset.hashtags)
      #hashtag_features = vectorizer2.fit_transform(hashtags).toarray()
      #hashtag_features = np.array(np.sum(hashtag_features, axis=1) > 0)[:, None]
      hashtag_features = self.vectorizer_concat.transform(test_dataset.hashtags)
      #hashtag_features = np.array(np.sum(hashtag_features, axis=1) > 0)[:, None]
  
      out_concat = sp.hstack([out, features1, features2, hashtag_features])
      out = out_concat.tocsr()
    
    return self.classifier.predict(out)

  def __get_vectors(self, text):
    vectors = []
    for sentence in text:
      vector = np.zeros(300)
      i=0
      for word in sentence.split():
        if word in self.word_vectors:
          vector += self.word_vectors[word]
        i += 1
      vector /= i
      vectors.append(vector)
    vectors = np.stack(vectors, 0)
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
  
  model = Model()
  #y_pred = model.train(train_dataset.text, train_dataset.labels)
  #compute_accuracy(train_dataset.labels, y_pred, "Train")
  model.trainBatch(train_dataset)
  #model.train(train_dataset)
  infer(model, train_dataset, "Train")
  infer(model, val_dataset, "Val")
  #infer(model, test_dataset, "Test")
    
if __name__ == "__main__":
  main()
