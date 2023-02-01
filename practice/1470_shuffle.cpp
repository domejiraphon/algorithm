class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    for (int i=0; i < n; i++){
      nums.insert(nums.begin() + 2*i +1, nums[i + n]);
      nums.erase(nums.begin() + i + n + 1);
    }
    return nums;
  }
};
