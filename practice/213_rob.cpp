#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;
void print(vector<int> cur){
  for (auto it : cur){cout << it<<", ";}
  cout << endl;
}
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {return nums[0];}
    int maxLeft = robHelper(vector<int> {nums.begin(), nums.end()-1});
    int maxRight = robHelper(vector<int> {nums.begin()+1, nums.end()});
    return (maxLeft > maxRight) ? maxLeft : maxRight;
  }
private:
  int robHelper(const vector<int>& nums) {
    if (nums.size() == 1) {return nums[0];}
    vector<int> memo(nums.size(), 0);
    memo[0] = nums[0]; 
    memo[1] = (nums[0] > nums[1]) ? nums[0]: nums[1];
    for (int i=2; i != nums.size(); i++){
      memo[i] = max(memo[i-1], nums[i] + memo[i-2]);
    }
    return memo[memo.size() - 1];
  }
};
int main()
{
  vector<int> nums = {1,2,3,1};
  
  Solution sol;
  cout << sol.rob(nums)<<endl;
  nums = vector<int> {2,7,9,3,1};

  cout << sol.rob(nums)<<endl;
  
  return 0;
}