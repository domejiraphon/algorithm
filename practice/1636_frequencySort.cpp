/*
1636. Sort Array by Increasing Frequency
Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.
*/
class Solution {
public:
  vector<int> frequencySort(vector<int>& nums) {
    int freq[201];
    memset(freq, 0, sizeof(freq));
    for (auto ele: nums)
      freq[ele+100]++;
    sort(nums.begin(), nums.end(), [&freq](int& a, int& b){
      return freq[a+100] == freq[b+100] ? a > b : freq[a+100] < freq[b+100];
    });
    return nums;
  }
};
