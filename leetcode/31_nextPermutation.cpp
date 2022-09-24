#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele :row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    vector<vector<int>> res;
    getPermutation(res, nums, 0, nums.size());
    sort(res.begin(), res.end());
    
    for (int i=0; i < res.size(); i++){
      if (nums == res[i]){
        nums = (i+1 < res.size()) ? res[i+1] : res[0];
        while(nums == res[i]){
          i++;
          nums = res[i];
        }
        
      }
    }
  }
private:
  void getPermutation(vector<vector<int>>& res, vector<int> nums, int low, int high){
    if (low == high){
      res.push_back(nums); return;
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
  /*
  sol -> nextPermutation(nums);
  print(nums);

  nums = {1, 2, 3};
  sol -> nextPermutation(nums);
  print(nums);*/

  nums = {1, 1, 5};
  sol -> nextPermutation(nums);
  print(nums);
  return 0;
}