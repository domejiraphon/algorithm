/*
1128. Number of Equivalent Domino Pairs
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
*/
class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<pair<int, int>, int> count;
    
    for (auto dominoe: dominoes){
      sort(dominoe.begin(), dominoe.end());
      count[{dominoe[0], dominoe[1]}]++;
    }
    int ans=0;
    for (auto it: count){
      ans +=  it.second *(it.second - 1) / 2;
    }
    return ans;
  }

};
