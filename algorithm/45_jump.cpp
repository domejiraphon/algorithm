/*
45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/
class Solution {
public:
  int jump(vector<int>& nums) {
    int n=nums.size();
    vector<int> memo(n, -1);
    return minJump(nums, 0, n, memo);
  }
private:
  int minJump(vector<int>& nums, int start, int& n, vector<int>& memo){
    if (start >= n - 1)
      return 0;
    if (memo[start] != -1)
      return memo[start];
    int count=INT_MAX /10;
    for (int i=1; i<=nums[start]; i++)
      count = min(count, 1 + minJump(nums, start + i, n, memo));
    
    return memo[start] = count;
  }
};

class Solution {
public:
  int jump(vector<int>& nums) {
    int n=nums.size();
    queue<int> Q;
    vector<bool> seen(n, false);
    seen[0] = true;
    int steps=0;
    Q.push(0);
    while (!Q.empty()){
      int numStack=Q.size();
      for (int i=0; i<numStack; i++){
        int cur = Q.front();
        if (cur >= n - 1)
          return steps;
        Q.pop();
        for (int j=1; j<=nums[cur]; j++){
          if (cur + j >= n - 1)
            return steps + 1;
          if (!seen[cur + j]){
            seen[cur + j] = true;
            Q.push(cur + j);
          }
        }
      }
      steps++;
    }
    return -1;
  }
};