#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int low(0), high(nums.size() - 1);
    vector<int> res(nums.size());
    int i(nums.size() - 1);
    while (low <= high){
      int cur;
      if (abs(nums[low]) < abs(nums[high])){
        cur = nums[high]; high--;
      }
      else {
        cur = nums[low]; low++;
      }
      res[i--] = cur *cur;
    }
    return res;
  }

};