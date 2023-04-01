/*
1528. Shuffle String
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.
*/
class Solution {
public:
  string restoreString(string s, vector<int>& indices) {
    int n=s.size();
    for (int i=0; i<n; i++){
      while (indices[i] != i){
        int tmp = indices[i];
        swap(s[i], s[tmp]);
        swap(indices[i], indices[tmp]);
      }
    }
    return s;
  }
};
