#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> vec){
  for (auto ele: vec){
    cout << ele << ", ";
  }
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> Set;
    unordered_map<int, vector<int>> hash;
    for (int i=0; i < nums.size() - 1; i++){
      for (int j=i+1; j < nums.size(); j++){
        if (hash.find(target - nums[i] - nums[j]) != hash.end(){
          vector<int> cur = {nums[i], nums[j]};
          cur.push_back(hash[target - nums[i] - nums[j]][0]);
          cur.push_back(hash[target - nums[i] - nums[j]][1]);
          Set.insert(cur);
        }
        else {
          hash[nums[i] + nums[j]] = 
        }
      }
    }
  }
};
int main()
{ 
  Solution* sol;
  vector<int> nums = {1,0,-1,0,-2,2};
  vector<vector<int>> out;
  out = sol -> fourSum(nums, 0);

  nums = {2,2,2,2,2};
  vector<vector<int>> out;
  out = sol -> fourSum(nums, 8);
  
  return 0;
}