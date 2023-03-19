/*
349. Intersection of Two Arrays
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> nums2S = {nums2.begin(), nums2.end()};
    unordered_set<int> nums1S = {nums1.begin(), nums1.end()};
    vector<int> res;
    for (auto n: nums1S){
      if (nums2S.count(n))
        res.push_back(n);
    }
    return res;
  }
};