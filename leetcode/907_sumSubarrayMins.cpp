/*
907. Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.
*/
class Solution {
private:
  int mod=pow(10, 9) + 7;
public:
  int sumSubarrayMins(vector<int>& arr) {
    stack<int> S;
    arr.push_back(0);
    int n=arr.size();
    long long sum=0;
    for (int i=0; i<n; i++){
      while (!S.empty() && arr[S.top()] > arr[i]){
        int mid = S.top();
        S.pop();
        int left = (S.empty()) ? -1 : S.top();
        long count = (i - mid) * (mid - left) % mod;
        sum += arr[mid] * count;
        sum %= mod;
      }
      S.push(i);
    }
    return sum;
  }
};
