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
  int pivotIndex(vector<int>& nums) {
    int n=nums.size();
    if (n ==  1){return 0;}
    int sum(0);
    for (int i=0; i < n; i++){
      sum += nums[i];
    }
    nums.insert(nums.begin(), 0);
    for (int i=1; i < (n+1); i++){
      if (nums[i - 1] == (sum - nums[i] - nums[i-1])){
        return i - 1;
      }
      nums[i] += nums[i - 1];
    }
    return -1;
  }
};
int main()
{ 
  Solution* sol;
  
  vector<int> nums = {1,7,3,6,5,6};
  cout << sol -> pivotIndex(nums) << endl;

  nums ={1, 0};
  cout << sol -> pivotIndex(nums) << endl;
  
  return 0;
}