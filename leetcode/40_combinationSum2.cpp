#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    set<vector<int>> Set;
    backtracking(res, target, candidates, vector<int> {}, Set, 0);
    return res;
  }
private:
  void backtracking(vector<vector<int>>& res, int target, 
        const vector<int> candidates, vector<int> cur, set<vector<int>>& Set,
        int start){
    if (target == 0){
      if (Set.find(cur) == Set.end()){
        res.push_back(cur); 
        Set.insert(cur);}
      return;}
    if (target < 0){return;}
    for (int i=start; i < candidates.size(); i++){
      if (i > start && candidates[i] == candidates[i-1]){
        continue;
      }
      vector<int> next={cur};
      next.push_back(candidates[i]);
      backtracking(res, target - candidates[i], candidates, next, Set, i + 1);
    }
  }
};

int main()
{
  Solution* sol;

  vector<int> candidates={10,1,2,7,6,1,5};
  vector<vector<int>> out;
  out = sol -> combinationSum2(candidates, 7);
  print(out);
  
  cout << endl;
  candidates = vector<int> {2,5,2,1,2,2};
  out = sol -> combinationSum2(candidates, 7);
  print(out);
  cout << endl;
  candidates = vector<int> {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  out = sol -> combinationSum2(candidates, 27);
  print(out);
  return 0;
}