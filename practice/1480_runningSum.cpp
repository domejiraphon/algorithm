#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> x){
  for (auto vec: x){
  cout << vec << ", ";
  
  }
  cout << endl;
}
class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    for (int i=1; i < nums.size(); i++){
      nums[i] = nums[i] + nums[i - 1];
    }
    return nums;
  }
};
int main()
{ 
  Solution* sol;
  
  vector<int> nums = {3,1,2,10,1};
  vector<int> out;
  out = sol -> runningSum(nums);
  print(out);
  return 0;
}