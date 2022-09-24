#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if(nums.size() == 1){return (nums[0] == target) ? 0:-1;}
    int pivot = getIdx(nums);
    int prev = nums[nums.size() - 1];
    
    int idx = helper(nums, target);
    cout << idx << ", "<< pivot << endl;
    if (idx < 0){return -1;}
    else if (target <= prev) {return idx + pivot;}
    else {return idx - (nums.size() - pivot);}
  }
private:
  int helper(vector<int>& nums, int target){
  
    if (nums[0] != target && nums.size() == 1){return -INT_MAX;}
    int idx = (int) nums.size() / 2;
    if (target == nums[idx]) {
      return idx;
    }
    else if (target < nums[idx]){
      vector<int> cur={nums.begin(), nums.begin() + idx};
      return helper(cur, target);
    }
    else {
      vector<int> cur={nums.begin() + idx, nums.end()};
      return idx + helper(cur, target);
    }
    
  }
  int getIdx(vector<int> nums){
    if (nums.size() == 0) {return 0;}
    else if (nums.size() == 1) {return 1;}
    else if (nums[0] < nums[nums.size() - 1]){return 0;}
    else if (nums.size() == 2){ return 1;}
    int mid = (int) nums.size() / 2;
    if (nums[mid] < nums[nums.size() - 1]){
      vector<int> cur={nums.begin(), nums.begin() + mid};
      return getIdx(cur);
    }
    else {
      vector<int> cur={nums.begin() + mid, nums.end()};
      return mid + getIdx(cur);
    }
  }
  void rotate(vector<int>& nums, int idx){
    
    vector<int> second = {nums.begin(), nums.begin() + idx};
    vector<int> first = {nums.begin() + idx, nums.end()};
   
    first.insert(first.end(), second.begin(), second.end());
    nums = first;
  }
};

int main()
{
  vector<int> nums = {4,5,6,7,0,1,2,};
  
  Solution* sol;
  
  //cout << sol -> search(nums, 0)<< endl;
  //cout << sol -> search(nums, 7)<< endl;
  //cout << sol -> search(nums, 2)<< endl;
  //cout << sol -> search(nums, 3)<< endl;

  nums = {3,4,5,6,7,8,1,2};
  cout << sol -> search(nums, 7)<< endl;
  return 0;
}