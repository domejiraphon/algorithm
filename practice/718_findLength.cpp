/*718. Maximum Length of Repeated Subarray
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 
*/
class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size();
    int m=nums2.size();
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(2, -1)));
    bool prev=false;
    return length(nums1, nums2, 0, 0, prev, n, m, memo);
  }
private:
  int length(vector<int>& nums1, vector<int>& nums2, int i, int j, bool prev, int& n, int& m, 
      vector<vector<vector<int>>>& memo){
    if (i==n || j == m)
      return 0;
    if (memo[i][j][prev] != -1)
      return memo[i][j][prev];
    int out=0;
    
    if (prev){
      if (nums1[i] == nums2[j])
        out = max(out, 1 + length(nums1, nums2, i+1, j+1, prev, n, m, memo));
      else
        out = 0;
    }
    else {
      out = max({out, length(nums1, nums2, i, j+1, false, n, m, memo),
                length(nums1, nums2, i+1, j, false, n, m, memo)});
      if (nums1[i] == nums2[j])
        out = max(out, 1 + length(nums1, nums2, i+1, j+1, true, n, m, memo));
     
    }
    
    return memo[i][j][prev] = out;
  }
};