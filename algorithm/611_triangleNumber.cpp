/* 611. Valid Triangle Number
Given an integer array nums, return the number of triplets chosen from the array that can make triangles 
if we take them as side lengths of a triangle.
*/
class Solution2 {
  vector<int> arr;
  int n;
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    arr = nums;
    n = nums.size();
    vector<int> cur={};
    return countTriangle(-1, cur);
  }
private:
  int countTriangle(int i, vector<int>& cur){
    if (cur.size() == 3)
      return (cur[0] + cur[1] > cur[2]) ? 1 : 0;
    int res=0;
    for (int j=i+1; j<n; j++){
      cur.push_back(arr[j]);
      res += countTriangle(j, cur);
      cur.pop_back();
    }
    return res;
  }
};

class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(), nums.end());
    int count=0;
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n && nums[i] != 0; j++){
        int k = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]) - nums.begin();
        count += k - j - 1;
      }
    }
    return count;
  }
};
