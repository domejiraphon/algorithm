/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    vector<int> prev = {1};
    res.push_back(prev);
    if (numRows == 1){
      return res;
    }
    for (int i=1; i<numRows; i++){
      vector<int> cur = {1};
      for (int j=0; j<prev.size()-1; j++){
        cur.push_back(prev[j] + prev[j+1]);
      }
      cur.push_back(1);
      res.push_back(cur);
      prev = cur;
    }
    return res;
  }
};