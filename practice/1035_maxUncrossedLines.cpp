/*
1035. Uncrossed Lines
You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.
*/
class Solution {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> memo(nums1.size(), vector<int>(nums2.size(), -1));
    return dp(0, 0, nums1, nums2, memo);
  }
private:
  int dp(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& memo){
    if (i == nums1.size() || j == nums2.size())
      return 0;
    if (memo[i][j] != -1)
      return memo[i][j];
    int ans=0;
    if (nums1[i] == nums2[j])
      ans = 1 + dp(i+1, j+1, nums1, nums2, memo);
    else
      ans = max({ans, dp(i+1, j, nums1, nums2, memo),
                dp(i, j+1, nums1, nums2, memo)});
    return memo[i][j] = ans;
  }
};
