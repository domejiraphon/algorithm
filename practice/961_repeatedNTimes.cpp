/*
961. N-Repeated Element in Size 2N Array
You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
*/
class Solution {
public:
  int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (auto n: nums)
      freq[n]++;
    int n = nums.size() / 2;
    for (auto it: freq)
      if (it.second == n)
        return it.first;
    return -1;
  }
};
