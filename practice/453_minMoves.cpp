class Solution {
public:
  int minMoves(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count(0);
    for (auto ele: nums){count += ele - nums[0];}
    return count;
  }
};
