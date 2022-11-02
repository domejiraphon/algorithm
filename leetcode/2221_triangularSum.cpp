#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
void print(vector<int> x){
  for (auto row: x){
    cout << row <<", ";
  }
  cout << endl;
}

class Solution {
public:
  int triangularSum(vector<int>& nums) {
    while (nums.size() > 1){
      sum(nums);
    }
    return nums[0];
  }
private:
  void sum(vector<int>& nums){
    int n = nums.size();
    
    for (int i=0; i < n -1; i++){
      nums[i] = (nums[i] + nums[i + 1]) % 10;
    }
    nums.pop_back();
  }
};

int main()
{ 
  
  Solution* sol = new Solution();
  vector<int> nums = {1,2,3,4,5};
  
  cout << sol -> triangularSum(nums)<< endl;
  return 0;
}