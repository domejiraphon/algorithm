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

void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    backtrack(nums, res, cur, 0, nums.size());
    return res;
  }
private:
  void backtrack(vector<int> nums, vector<vector<int>>& res, 
        vector<int> cur, int round, int n){
    if (round == n){res.push_back(cur); return;}
    
    for (int i=0; i < nums.size(); i++){
      if (i >= 1 && nums[i] == nums[i-1]){continue;}
      vector<int> tmp=nums;
      tmp.erase(tmp.begin() +i);
      cur.push_back(nums[i]);
      backtrack(tmp, res, cur, round +1, n);
      cur.pop_back();
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
  print(out);

}
