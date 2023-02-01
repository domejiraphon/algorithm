#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele<<", ";
    }
    cout << endl;
  }
}



class myComparator{
public:
  int operator() (tuple<int, int, int> a, tuple<int, int, int> b){
    return get<0>(a) > get<0>(b);}};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, myComparator> minHeap;
      int counter(0);
      for (auto ele1: nums1){
        for (auto ele2: nums2){
          tuple<int, int, int> cur = {ele1 + ele2, ele1, ele2};
          minHeap.push(cur);
        }
        counter++;
        if (counter == k){break;}
      }
      counter = 0;
  
      vector<vector<int>> out;
      while (!minHeap.empty()){
        tuple<int, int, int> p = minHeap.top();
        out.push_back(vector<int> {get<1>(p), get<2>(p)});
        minHeap.pop();
        counter++;
        if (counter==k){break;}
      }
      return out;
    }
};

int main()
{
  vector<int> nums1 = {1, 7, 11};
  vector<int> nums2 = {2, 4, 6};

  
  Solution sol;
  vector<vector<int>> out;
  out = sol.kSmallestPairs(nums1, nums2, 3);
  print(out);
  return 0;
}