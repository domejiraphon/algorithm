#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
class Solution {
public:
  int search(vector<int>& nums, int target) {
    
    if (nums.size() == 1){
      return (nums[0] ==  target) ? 0 : -1;
    }
    int idx = (int) nums.size() / 2;
    if (nums[idx] == target){
      return idx;
    }
    else if (nums[idx] > target){
      vector<int> cur = {nums.begin(), nums.begin() + idx};

      return search(cur, target);
    }
    else {
      vector<int> cur = {nums.begin() + idx, nums.end()};
      int out = search(cur, target);
      return (out != -1) ? out +idx : out;
    }

  }
};
int main()
{ 
  
  Solution* sol;
  vector<int> nums = {-1,0,3,5,9,12};
  cout << sol -> search(nums, 9)<< endl;

  nums = {-1,0,3,5,9,12};
  cout << sol -> search(nums, 2)<< endl;
  return 0;
}