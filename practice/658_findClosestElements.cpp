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
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class myComparator{
public:
  int operator() (pair<int, int> a, pair<int, int> b){
    return (a.first < b.first) ? true : (a.first == b.first) ? (a.second > b.second) : false;}
};

class Solution2 {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparator> maxHeap;
    for (auto ele: arr){
      if (maxHeap.size() < k){
        maxHeap.push({abs(ele - x), ele});
      }
      else {
        pair<int, int> top = maxHeap.top();
        if (top.first > abs(ele - x)){
          maxHeap.pop();
          maxHeap.push({abs(ele - x), ele});
        }
      }
    }
    vector<int> res;
    while (!maxHeap.empty()){
      res.push_back(maxHeap.top().second); maxHeap.pop();
    }
    sort(res.begin(), res.end());
    return res;
  }
};

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int left(idx-1), right(idx), n(arr.size());
    
    while (right - left < k){
      if (left == -1 || right < n && abs(arr[right] - x) < abs(arr[left] - x)){
        right++;
      }
      else {
        left--;
      }
    }
    cout << left << right;
    return vector<int> {arr.begin() + left, arr.begin() + right};
  }
};
int main()
{
  vector<int> nums={1,2,3,4,7,-1};
  
  Solution* sol;
  vector<int> out;
  out = sol -> findClosestElements(nums, 4, -1 );
  print(out);
  return 0;
}