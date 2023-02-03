/*
1064. Fixed Point
Given an array of distinct integers arr, where arr is sorted in ascending order, return the smallest index i that satisfies arr[i] == i. If there is no such index, return -1.
*/
class Solution {
public:
  int fixedPoint(vector<int>& arr) {
    int n=arr.size();
    for (int i=0; i<n; i++)
      if (arr[i] == i)
        return i;
    return -1;
  }
};
