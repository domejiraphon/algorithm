class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n=nums.size();
    int cur(0);
    for (int i=0; i < n; i++){
      if (nums[i] != 0){
        nums[cur++] = nums[i];
      }
    }
    for (int i=cur; i<n; i++){
      nums[i] = 0;
    }
  }
};

class Solution2 {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int idx=nums.size() - 1;
    for (int i=idx; i>=0; i--){
      if (nums[i] == 0){
        for (int j=i; j<idx; j++){
          if (j==i){swap(nums[i], nums[i+1]);}
          else {swap(nums[j+1], nums[j]);}
        }
        idx--;
      }
    }
  }
};
