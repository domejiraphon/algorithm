/* 1696. Jump Game VI
You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, 
you can jump at most k steps forward without going outside the boundaries of the array. 
That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). 
Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.
*/
class Solution2 {
public:
  int maxResult(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> dp(n, INT_MIN /10);
    dp[0] = nums[0];
    for (int i=1; i<n; i++){
      for (int j=0; j<=k && i-j>= 0; j++){
        dp[i] = max(dp[i], nums[i] + dp[i - j]);
      }
    }
    return dp[n - 1];
  }
};
class Compare {
public:
  bool operator () (pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
  }
};
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    int n=nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;
    maxHeap.push({0, nums[0]});
    vector<int> memo(n, INT_MIN / 10);
    memo[0] = nums[0];
    for (int i=1; i<n; i++){
      while (i - maxHeap.top().first > k){
        maxHeap.pop();
      }
      memo[i] = nums[i] + maxHeap.top().second;
      maxHeap.push({i, memo[i]});
    }
    return memo[n - 1];
  }
};