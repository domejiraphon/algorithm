/*
1043. Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.
*/
class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n=arr.size();
    vector<int> out(n, -1);
    return maxSum(arr, 0, k, n, out);
  }
private:
  int maxSum(vector<int>& arr, int start, int k, int& n, vector<int>& out){
    if (start == n)
      return 0;
    if (out[start] != -1)
      return out[start];
    int cur=0;
    int prev = arr[start];
    for (int i=start; i<n && i-start<k; i++){
      prev = max(prev, arr[i]);
      cur = max(cur, prev*(i - start + 1) + maxSum(arr, i+1, k, n, out));
    }
    return out[start] = cur;
  }
};
