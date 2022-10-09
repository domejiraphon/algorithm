#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <unordered_set>
#include <stack>
#include <tuple>

using namespace std;

void print(vector<int> x){
  for (auto elem: x){
    cout << elem <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftSide(n);
    vector<int> rightSide(n);
    leftSide[0] = nums[0];
    rightSide[n - 1] = nums[n - 1];
    for (int i=1; i < n; i++){
      leftSide[i] = nums[i] * leftSide[i - 1];
    }
    for (int i=n - 1; i >= 1; i--){
      rightSide[i - 1] = nums[i-1] * rightSide[i];
    }
    vector<int> out(n);
    out[0] = rightSide[1];
    for (int i=1; i < n - 1; i++){
      out[i] = leftSide[i -1] * rightSide[i + 1];
    }
    out[n - 1] = leftSide[n - 2];
    return out;
  }
};

int main()
{ 
  vector<int> nums;
  Solution* sol;
  nums = {1,2,3,4, 5};
  vector<int> out;
  out = sol -> productExceptSelf(nums);
  print(out);

  nums = {3,2};
  out = sol -> productExceptSelf(nums);
  print(out);

  nums = {1};
  out = sol -> productExceptSelf(nums);
  print(out);
  return 0;
}