#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
void print(vector<vector<T>> x){
  for (auto row: x){
    for (auto elem: row) {
      cout << elem <<", ";}
    cout << endl;
  }
  
}

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> subset{};
    map<vector<int>, bool> duplicate;
    backtracking(res, subset, candidates, target, duplicate);
    return res;
  }

private:
  void backtracking(vector<vector<int>>& res, vector<int> subset,
        const vector<int>& candidates, int target, 
        map<vector<int>, bool>& duplicate){
    if (target == 0){
      sort(subset.begin(), subset.end());
      if (duplicate.find(subset) == duplicate.end()){
        res.push_back(subset);
        duplicate[subset] = true;
      }
      return;
    }
    else if (target < 0){return;}
    else {
      for (auto sel : candidates){
        vector<int> cur{subset};
        cur.push_back(sel);

        backtracking(res, cur, candidates, target - sel, duplicate);
      }
    }

  }
};

int main()
{
  Solution sol;

  vector<int> candidates={2,3,6,7};
  vector<vector<int>> out;
  out = sol.combinationSum(candidates, 7);
  print(out);

  candidates = vector<int> {2,3,5};
  out = sol.combinationSum(candidates, 8);
  print(out);

  candidates = vector<int> {2};
  out = sol.combinationSum(candidates, 1);
  print(out);
  return 0;
}