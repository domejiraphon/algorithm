#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
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
    vector<int> subset;
    backtracking(res, subset, candidates, target, 0);
    return res;
  }

private:
  void backtracking(vector<vector<int>>& res, vector<int> subset,
        const vector<int>& candidates, int target, int start){
    if (target == 0){
      sort(subset.begin(), subset.end());
      res.push_back(subset);
      return;
    }
    else if (target < 0){return;}
    else {
      for (int i=start; i < candidates.size(); i++){
        vector<int> cur{subset};
        cur.push_back(candidates[i]);
        backtracking(res, cur, candidates, target - candidates[i], i);
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
  cout << endl;
  candidates = vector<int> {2,3,5};
  out = sol.combinationSum(candidates, 8);
  print(out);

  candidates = vector<int> {100,200,4,12};
  out = sol.combinationSum(candidates, 400);
  print(out);
  return 0;
}