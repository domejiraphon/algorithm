#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0){return vector<int> {-1, -1};}
    int start = findStart(nums, target);
    if (start < 0){start = -1;}
    int end = findEnd(nums, target);
  
    if (end < 0){end = -1;}
    return vector<int> {start, end};
  }
private:
  int findStart(vector<int> nums, int target){
    int n = nums.size();
    if (n == 1){return (nums[0] == target) ? 0: INT_MIN;}
    if (n == 2){
      if (nums[0] == target){return 0;}
      else if (nums[1] == target){return 1;}
      else {return INT_MIN;}
    }
    int mid = (int) n / 2;
    if (nums[mid] >= target){
      return findStart(vector<int> {nums.begin(), nums.begin() + mid + 1}, target);
    }
    else {
      return mid + findStart(vector<int> {nums.begin()+mid, nums.end()}, target);
    }
  }
  
  int findEnd(vector<int> nums, int target){
    int n = nums.size();
    if (n == 1){return (nums[0] == target) ? 0: INT_MIN;}
    if (n == 2){
      if (nums[1] == target){return 1;}
      else if (nums[0] == target){return 0;}
      else {return INT_MIN;}
    }
    
    int mid = (int) n / 2;
 
    if (nums[mid] <= target){
      return mid + findEnd(vector<int> {nums.begin()+mid, nums.end()}, target);
    }
    else {
      return  findEnd(vector<int> {nums.begin(), nums.begin() + mid + 1}, target);
    }
  }
};

int main()
{
  Solution* sol;
  vector<int> nums = {5,7,7,8,8,8,10};
  vector<int> out;
  
  out = sol -> searchRange(nums, 8);
  print(out);

  nums = {5,7,7,8,8,10};
  out = sol -> searchRange(nums, 6);
  print(out);

  nums = {};
  out = sol -> searchRange(nums, 0);
  print(out);

  nums = {2, 2, 2};
  out = sol -> searchRange(nums, 2);
  print(out);
}
