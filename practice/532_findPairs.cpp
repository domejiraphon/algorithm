class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int left(0), right(1);
    int res(0);
    while (right < n && left < n){
      if (left == right || nums[right] - nums[left] < k){
        right++;
      }
      else if (nums[right] - nums[left] > k){
        left++;
      }
      else {
        res++; left++;
        while (left < n && nums[left] == nums[left - 1]){
          left++;
        }
      }
    }
    return res;
  }
};
