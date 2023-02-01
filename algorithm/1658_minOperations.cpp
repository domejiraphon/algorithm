class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size(), count(0);
    for (int i=0; i < n; i++){count += nums[i];}
    int left(0), cur(0);
    int longest(INT_MIN);
    for (int right=0; right < n; right++){
      
      cur += nums[right];
      while (cur > count - x && left <= right){
        cur -= nums[left++];
      }
      if (cur == count - x){
        longest = max(longest, right - left + 1);
      }
    }
    return (longest != INT_MIN) ? n - longest : -1;
  }
};
