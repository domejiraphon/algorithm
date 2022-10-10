#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
     vector<vector<int>> res;
     vector<int> cur;
     backtrack(nums, res, cur, nums.size());
     //print(res); exit(0);
     exit(0);
     return res;
  }
private:
  void backtrack(vector<int> nums, vector<vector<int>>& res, 
        vector<int> cur, int n){
    
    if (nums.size() == 0){res.push_back(cur); return;}
    if (nums.size() == 1){cur.push_back(nums[0]); res.push_back(cur); return;}
    for (int i=0; i < n; i++){
      vector<int> tmp=nums;
      tmp.erase(tmp.begin() +i);
      print(tmp);
      vector<int> cur;
      cur.push_back(nums[i]);
      backtrack(tmp, res, cur, n);
    }
  }
};
int main()
{
  Solution* sol;
  vector<vector<int>> out;
  vector<int> nums;

  nums = {1,1,2};
  out = sol -> permuteUnique(nums);
}
