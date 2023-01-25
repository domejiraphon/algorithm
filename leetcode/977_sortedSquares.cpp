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

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int& a, int& b){
        return pow(a, 2) < pow(b, 2);
      });
    int n=nums.size();
    for (int i=0; i<n; i++)
      nums[i] *= nums[i];
    return nums;
  }
};