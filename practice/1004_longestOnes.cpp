#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int>& nums, int k) {
    int left(0), n(nums.size());
    int right;
    int maxL(INT_MIN);
    for (right=0; right < n; right++){
      if (nums[right] == 0){k--;}
      if (k < 0){
        k += nums[left] == 0;
        left++;
      }
    }
    return right - left;
  }
};

int main()
{ 
  
  Solution* sol;
  
  vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
  cout << sol -> longestOnes(nums, 2) << endl;


  nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  cout << sol -> longestOnes(nums, 3) << endl;
  return 0;
}