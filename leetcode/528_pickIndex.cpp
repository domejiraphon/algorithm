#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
void print(set<vector<int>> x){
  for(auto it=x.begin(); it != x.end(); it++){
    for (auto ele: *it){
      cout << ele << ", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    set<vector<int>> res;
    getPermutation(res, nums, 0, nums.size());
   
    vector<vector<int>> out = {res.begin(), res.end()};
    for (int i = 0; i < out.size(); i++){
      if (i == out.size() - 1){nums = out[0]; break;}
      if (out[i] == nums){nums = out[i + 1]; break;}
    }
  }
private:
  void getPermutation(set<vector<int>>& res, vector<int> nums, int low, int high){
    if (low == high){
      res.insert(nums); return;
    }
    
    for (int i=low; i != high; i++){
      swap(nums[low], nums[i]);
      getPermutation(res, nums, low+1, high);
      
    }
  }
};

int main()
{
  
  Solution* sol;
  vector<int> nums={3, 2, 1};
  
  //sol -> nextPermutation(nums);
  //print(nums);
  
  nums = {1, 2, 3};
  //sol -> nextPermutation(nums);
  //print(nums);

  nums = {1};
  sol -> nextPermutation(nums);
  print(nums);
  return 0;
}