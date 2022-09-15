#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

void print(vector<int> x){
  for (auto ele: x){
    cout << ele <<", ";
  }
   cout << endl;
}

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
   int close(INT_MAX-abs(target));
  for (int i=0; i != nums.size(); i++){
    int low(i+1), high(nums.size() -1);
    while(low < high){
      int diff = nums[i] + nums[low] + nums[high] - target;
      if (diff == 0){
        return target;
      }
      else if (diff > 0){
        if (diff < abs(close - target)) {close = target+diff;}
        high--;
      }
      else {
        if (diff < abs(close - target)) {close = target+diff;}
        low++;
      }
    }
  }
  return close;
  }
};

int main()
{
  
  Solution sol;
  vector<vector<int>> out;
  vector<int> nums = {-1, 2, 1, -4};
  cout << sol.threeSumClosest(nums, 1)<< endl;
  
  nums = vector<int> {1, 1, 1, 1};
  cout << sol.threeSumClosest(nums, -100)<< endl;
  
  return 0;
}