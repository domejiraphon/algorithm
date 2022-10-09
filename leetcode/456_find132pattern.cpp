#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;
class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n-2; i++){
      cout << nums[i] << nums[i+1]<< nums[i+2]<<endl;
      if (nums[i] < nums[i+1] && nums[i+2] < nums[i + 1]){
        return true;
      }
    }
    return false;
  }
};
int main()
{ 
  
  Solution* sol;
  vector<int> nums;
  /*
  nums = {1,2,3,4};
  cout << sol -> find132pattern(nums)<< endl;

  nums = {3,1,4,2};
  cout << sol -> find132pattern(nums)<< endl;
  */
  nums = {1, 0, 1, -4, -3};
  cout << sol -> find132pattern(nums)<< endl;
  return 0;
}