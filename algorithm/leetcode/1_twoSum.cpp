/*
1. twoSum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Approach 3: One-pass Hash Table
Algorithm
It turns out we can do it in one-pass. While we are iterating and inserting elements into the hash table, 
we also look back to check if current element's complement already exists in the hash table. 
If it exists, we have found a solution and return the indices immediately.

Complexity Analysis

Time complexity: O(n). We traverse the list containing nnn elements only once. 
Each lookup in the table costs only O(1) time.

Space complexity: O(n). The extra space required depends on the number of items stored in the hash table, 
which stores at most nnn elements.
*/

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    vector<int> out;
    int n = nums.size();
    for (int i = 0; i < n; i++){
      if (hash.count(nums[i])){
        out.push_back(hash[nums[i]]);
        out.push_back(i); break;
      }
      else{
        hash[target - nums[i]] = i;
      }
    }
    return out;
  }
};