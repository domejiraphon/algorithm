#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<vector<int>> x){
  for (auto vec: x){
    for (auto ele: vec){
    cout << ele << ", ";
    }
  cout << endl;
  }
}

class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    return word1.size() + word2.size() - 2*lcs(word1, word2, word1.size(), word2.size(), memo);
  }
private:
  int lcs(string word1, string word2, int idx1, int idx2, vector<vector<int>>& memo){
    if (idx1 ==0 || idx2 == 0){return 0;}
    if (memo[idx1][idx2] != -1){
      return memo[idx1][idx2];
    }
    if (word1[idx1-1] == word2[idx2-1]){
      memo[idx1][idx2] = 1 + lcs(word1, word2, idx1-1, idx2-1, memo);
    }
    else {
      memo[idx1][idx2] = max(lcs(word1, word2, idx1, idx2-1, memo), 
                            lcs(word1, word2, idx1-1, idx2, memo));
    }
    return memo[idx1][idx2];
  }
};

int main()
{ 
  Solution* sol;
  cout << sol -> minDistance("a", "b")<< endl;
  cout << sol -> minDistance("leetcode", "etco")<< endl;
  cout << sol -> minDistance("seaqt", "eat")<< endl;
  return 0;
}