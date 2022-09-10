#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> out;
    int low(0), high(nums.size()-1);
    while(low < high){
      if(target == nums[low] + nums[high]){
        out.push_back(low+1); out.push_back(high+1); return out;
      }
      else if (target > nums[low] + nums[high]){
        low++;
      }
      else {
        high--;
      }
    }
  }
};

int main()
{
  
  Solution sol;
  vector<int> out;
  vector<int> nums = {2,7,11,15};
  out = sol.twoSum(nums, 9);
  print(out);

  vector<int> nums2 = {2,3,4};
  out = sol.twoSum(nums2, 6);
  print(out);

  vector<int> nums3 = {-1, 0};
  out = sol.twoSum(nums3, -1);
  print(out);
  
  return 0;
}