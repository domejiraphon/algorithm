/*
189. Rotate Array

Given an array, rotate the array to the right by k steps, where k is non-negative.
*/
class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    int count=0;
    for (int i=0; count < n; i++){
      int cur = i;
      int prev = nums[cur];
      do {
        int next = (cur + k) % n;
        int tmp = nums[next];
        nums[next] = prev;
        prev = tmp;
        cur = next;
        count++;
      } while (cur != i);
    }
  }
};