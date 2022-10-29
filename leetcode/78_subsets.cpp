#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    backtrack(0, nums, cur, res);
    return res;
  }
private:
  void backtrack(int idx, vector<int>& nums, 
      vector<int> cur, vector<vector<int>>& res){
    int n = nums.size();
    if (idx == n){ 
      res.push_back(cur);
      return;}
    backtrack(idx + 1, nums, cur, res);
    cur.push_back(nums[idx]);
    backtrack(idx + 1, nums, cur, res);
    cur.pop_back();
    
  }
};
int main()
{
  Solution* sol;
  vector<int> nums = {1, 2, 4};
  vector<vector<int>> out;
  out = sol -> subsets(nums);

  nums = {0};
  out = sol -> subsets(nums);
}
