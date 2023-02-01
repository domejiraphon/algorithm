/*
496. Next Greater Element I
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> stk;
    int i=0, n=nums2.size();
    while (i<n){
      while (!stk.empty() && stk.top() < nums2[i]){
        nextGreater[stk.top()] = nums2[i];
        stk.pop();
      }
      stk.push(nums2[i++]);
    }
    while (!stk.empty()){
      nextGreater[stk.top()] = -1;
      stk.pop();
    }
    vector<int> res(nums1.size());
    n = nums1.size();
    for (int i=0; i<n; i++){
      res[i] = nextGreater[nums1[i]];
    }
    return res;
    
  }
};
