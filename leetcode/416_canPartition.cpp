#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
void print(map<pair<int, int>, bool> memo){
  for (auto it=memo.begin(); it != memo.end(); it++){
    cout << "(" << it -> first.first << ", "<< it -> first.second << ")";
    cout << it -> second << endl;
  }
}

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum(0);
    for (int i=0; i < n; i++){sum += nums[i];}
    if (sum % 2 == 1){return false;}
    map<pair<int, int>, bool> memo;
    bool out = backtracking(nums, (int) sum/2, 0, n, memo);
    return out;
  }

private:
  bool backtracking(vector<int> nums, int target, int start, int n,
      map<pair<int, int>, bool>& memo){
    if (target < 0){return false;}
    if (target == 0){return true;}
    bool result;
    for (int i=start; i< n; i++){
      if (i > start && nums[i] == nums[i-1]){
        continue;
      }
      if (memo.find({nums[i], target}) != memo.end()){
        return memo[{nums[i], target}];
      }
      result = backtracking(nums, target - nums[i], i + 1, n, memo)
                || backtracking(nums, target, i + 1, n, memo);
      memo[{nums[i], target}] = result;
     
    }
    return result;
  }
};

int main()
{ 
  vector<int> nums;
  Solution* sol;
  nums = {1, 5, 11, 5};
  cout << sol -> canPartition(nums)<< endl;
  nums = {2, 2, 3, 5};
  cout << sol -> canPartition(nums)<< endl;
  nums = {1,2,5};
  cout << sol -> canPartition(nums)<< endl;

  nums = {1, 2,2,5, 5, 11};
  cout << sol -> canPartition(nums)<< endl;
  return 0;
}