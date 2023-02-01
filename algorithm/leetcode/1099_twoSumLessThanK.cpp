#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  int twoSumLessThanK(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int count=-1;
    int low(0), high(nums.size()-1);
    while(low < high){
      if (k > nums[low] + nums[high]){
        count = max(count, nums[low] + nums[high]);
        low++;
      }
      else {
        high--;
      }
    }
    return count;
  }
};

int main()
{
  
  Solution sol;
  vector<int> nums = {34,23,1,24,75,33,54,8};
  cout << sol.twoSumLessThanK(nums, 60)<< endl;
  
  vector<int> nums2 = {10,20,30};
  cout << sol.twoSumLessThanK(nums2, 15)<< endl;

  return 0;
}