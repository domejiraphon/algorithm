class Solution {
public:
  int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    vector<int> pos1;
    vector<int> pos2;
    int n=wordsDict.size();
    for (int i=0; i<n; i++){
      if (word1 == wordsDict[i])
        pos1.push_back(i);
      else if(wordsDict[i] == word2)
        pos2.push_back(i);
    }
    int minDist=INT_MAX;
    for (int i=0; i<pos1.size(); i++){
      for (int j=0; j<pos2.size(); j++)
        minDist = min(minDist, abs(pos2[j] - pos1[i]));
    }
    return minDist;
  }
};
