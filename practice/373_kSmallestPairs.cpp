/*
373. Find K Pairs with Smallest Sums
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.
*/
class Compare {
public:
  bool operator () (pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
    return a.first > b.first;
  }
};

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> maxHeap;
    int n1 = nums1.size();
    int n2 = nums2.size();
    for (int i=0; i<n1; i++)
      maxHeap.push({nums1[i] + nums2[0], {i, 0}});
    vector<vector<int>> res;
    while (!maxHeap.empty() && k > 0){
      pair<int, pair<int, int>> cur = maxHeap.top();
      int i = cur.second.first, j = cur.second.second;
      res.push_back({nums1[i], nums2[j]});
      maxHeap.pop();
      if (j < n2 - 1)
        maxHeap.push({nums1[i] + nums2[j+1], {i, j+1}});
      k--;
    }
    return res;
  }
};