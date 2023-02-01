/*
2104. Sum of Subarray Ranges

You are given an integer array nums. 
The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
  long long subArrayRanges(vector<int>& nums) {
    int n=nums.size();
    long long sum=0;
    for (int i=0; i<n ;i++){
      int minVal = INT_MAX;
      int maxVal = INT_MIN;
      for (int j=i; j<n; j++){
        minVal = min(minVal, nums[j]);
        maxVal = max(maxVal, nums[j]);
        sum += maxVal - minVal;
      }
    }
    return sum;
  }
};

class Solution {
public:
  long long subArrayRanges(vector<int>& nums) {
    stack<int> minStk;
    stack<int> maxStk;
    int n=nums.size();
    long long sum=0;

    for (int i=0; i<=n; i++){
      while (!minStk.empty() && (i == n || nums[minStk.top()] >= nums[i])){
        int mid = minStk.top();
        minStk.pop();
        int left = minStk.empty() ? -1 : minStk.top();
        sum -= (long long)nums[mid] * (i - mid) * (mid - left);
      }
      minStk.push(i);

      while (!maxStk.empty() && (i == n || nums[maxStk.top()] <= nums[i])){
        int mid = maxStk.top();
        maxStk.pop();
        int left = maxStk.empty() ? -1 : maxStk.top();
        sum += (long long)nums[mid] * (i - mid) * (mid - left);
      }
      maxStk.push(i);
    }
    return sum;
  }
};
