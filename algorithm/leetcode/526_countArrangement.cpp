/*
526. Beautiful Arrangement
Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.
*/
class Solution {
public:
  int countArrangement(int n) {
    vector<int> nums(n+1);
    for (int i=1; i<=n; i++)
      nums[i] = i;
    return beautiful(nums, 1, n);
  }
private:
  int beautiful(vector<int>& nums, int st, int& n){
    if (st == n+1)
      return 1;
    int out=0;
    for (int i=st; i<= n; i++){
      if (nums[i] % st == 0 || st % nums[i] == 0){
        swap(nums[i], nums[st]);
        out += beautiful(nums, st + 1, n);
        swap(nums[i], nums[st]);
      }
    }
    return out;
  }
};