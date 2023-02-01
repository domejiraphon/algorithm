/*
1574. Shortest Subarray to be Removed to Make Array Sorted
Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.
*/
class Solution {
public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int n=arr.size();
    int r=n-1;
    while (r >=1 && arr[r] >= arr[r-1])
      r--;
    
    int res=r;
    
    for (int l=0; l <r && (l == 0 || arr[l-1] <= arr[l]); l++){
      while (r < n && arr[l] > arr[r])
        r++;
      
      res = min(res, r - l - 1);
    }
    
    return res;
  }
};