#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 1){
      return target > nums[0] ? 1 : 0;
    }
    int pos=(int) nums.size()/2;
    int median=nums[pos];
    cout << median << endl;
    if (median < target) {
      vector<int> subvector = {nums.begin() + pos, nums.end()};
      return pos + searchInsert(subvector, target);
    }
    else {
      vector<int> subvector = {nums.begin(), nums.begin() + pos};
      return searchInsert(subvector, target);
    }
  }
};

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(8);
  Solution sol;
  cout << sol.searchInsert(nums, 2) << endl;
  return 0;
}