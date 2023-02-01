/*
244. Shortest Word Distance II
Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.
*/
class WordDistance {
  unordered_map<string, vector<int>> map;
public:
  WordDistance(vector<string>& wordsDict) {
    int n=wordsDict.size();
    for (int i=0; i<n; i++)
      map[wordsDict[i]].push_back(i);
  }
  
  int shortest(string word1, string word2) {
    int minDist = INT_MAX;
    for (int l: map[word1]){
      for (int r: map[word2]){
        minDist = min(minDist, abs(l - r));
      }
    }
    return minDist;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */