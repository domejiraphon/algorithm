#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

void print(map<string, vector<int>> x){
  for (auto it=x.begin(); it != x.end(); it++){
    cout << it -> first <<":";
    for(auto elem: it -> second){
      cout << elem << ", ";
    }
    cout << endl;
  }
}

class WordDistance {
private:
  map<string, vector<int>> hashTable;
public:
  WordDistance(vector<string>& wordsDict) {
    for (int i=0; i != wordsDict.size(); i++){
      hashTable[wordsDict[i]].push_back(i);
    }
  }
  
  int shortest(string word1, string word2) {
    vector<int> idxWord1 = hashTable[word1];
    vector<int> idxWord2 = hashTable[word2];
    int dist(INT_MAX);
    for (int i = 0; i != idxWord1.size(); i++){
      for (int j=0; j != idxWord2.size(); j++){
        dist = min(dist, abs(idxWord1[i] - idxWord2[j]));
      }
    }
    return dist;
  }
};

int main()
{ 
  vector<string> wordsDict = {"practice", "makes", "perfect", "coding", "makes"};
  WordDistance* obj = new WordDistance(wordsDict);
  cout << obj->shortest("coding", "practice") << endl;
  cout << obj->shortest("makes", "coding") << endl;
  
  return 0;
}