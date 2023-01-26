/*
238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> res(n);
    vector<int> pos;
    int prod=1;
    for (int i=0; i<n; i++){
      if (nums[i] != 0)
        prod *= nums[i];
      else
        pos.push_back(i);
      if (pos.size() > 1){
        res.resize(n, 0);
        return res;
      }
    }
    if (pos.size() == 0){
      for (int i=0; i<n; i++){
        res[i] = prod / nums[i];
      }
    }
    else {
      res.resize(n, 0);
      res[pos[0]] = prod;
    }
   
    return res;
  }
};