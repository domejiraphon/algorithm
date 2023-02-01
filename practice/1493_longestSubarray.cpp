/*
1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/
class Solution2 {
public:
  int longestSubarray(vector<int>& nums) {
    nums.push_back(0);
    int n=nums.size();
    int left=0, right=0;
    vector<pair<int, int>> pos;
    while (right < n){
      if (nums[right] == 0){
        if (right != left){
          pos.push_back({left, right-1});
        }
        right++; left = right; continue;
      }
      else {
        right++;
      }
    }
    if (pos.size() == 0)
      return 0;
    if (pos.size() == 1 && pos[0].first == 0 && pos[0].second == n-1)
      return n-2;
    
    int maxVal = pos[0].second - pos[0].first;
    n = pos.size();
   for (int i=0; i<n; i++){
     cout << pos[i].first <<", "<<pos[i].second<<endl;
   }
   
    for (int i=0; i<n-1; i++){
      
      if (pos[i+1].first - pos[i].second == 2){
      
        maxVal = max(maxVal, pos[i+1].second - pos[i+1].first+1 +pos[i].second -pos[i].first+1);
      }
        
    }
    return maxVal;
  }
};
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int left=0;
    int right=0;
    int n=nums.size();
    int k=1;
    int res=0;
    while (right < n){
      if (nums[right] ==0)
        k--;
      while (left < right && k < 0){
        if (nums[left]==0)
          k++;
        left++;
      }
      res = max(res, right - left);
      right++;
    }

    return res;
  }
};