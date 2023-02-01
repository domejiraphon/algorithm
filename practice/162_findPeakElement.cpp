#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    cout << INT_MIN << endl;
    int mid = (int) nums.size() / 2;
    int left = (mid > 0) ? nums[mid - 1] : INT_MIN;
    int right = (mid < nums.size() - 1) ? nums[mid + 1] : INT_MIN;
    if (nums[mid] > left && nums[mid] > right){
      return mid;
    }
    else if (nums[mid] <= right){
      vector<int> cur = {nums.begin() + mid, nums.end()};
      return mid + findPeakElement(cur);
    }
    else {
      vector<int> cur = {nums.begin(), nums.begin() + mid};
      return findPeakElement(cur);
    }
  }
};
int main()
{ 
  vector<int> nums = {1,2,1,3,5,6,4};
  Solution* sol;

  cout << sol -> findPeakElement(nums);
  nums = {-2147483648};
  cout << sol -> findPeakElement(nums);
  return 0;
}