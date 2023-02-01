#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
template <typename T>
void print(const vector<T> & vec)
{
    for(auto ele : vec)
    {
      cout << ele << ", ";
    }
    cout <<endl;
    
}
void print(vector<tuple<int, string>> vec)
{
    for(auto ele : vec)
    {
      cout << get<0>(ele) << ", "<< get<1>(ele)<< endl;
    }
    cout <<endl;
  
}

class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    int low, high;
    for (low=0; low != nums.size() - 1; low++){
      if (nums[low] != tmp[low]){
        break;
      }
    }
    for (high= nums.size() - 1; high >= 0; high--){
      if (nums[high] != tmp[high] || high <low){
        break;
      }
    }
    return high - low + 1;
  }
};

int main()
{ 
  Solution* sol;
  vector<int> nums = {2,6,4,8,10,9,15};
  cout << sol -> findUnsortedSubarray(nums)<<endl;

  nums = {1,2,3,4};
  cout << sol -> findUnsortedSubarray(nums)<<endl;

  nums = {1};
  cout << sol -> findUnsortedSubarray(nums)<<endl;
  return 0;
}