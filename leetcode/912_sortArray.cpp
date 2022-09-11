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
  vector<int> sortArray(vector<int>& nums) {
    if (nums.size() == 1 || nums.size() ==0) {return nums;}
    //int pivotIdx = rand() % nums.size();
    int pivotIdx = nums.size() -1;
    int idx = partition(nums, pivotIdx);
   
    vector<int> left = {nums.begin(), nums.begin()+idx};
    vector<int> right = {nums.begin()+idx+1, nums.end()};
    vector<int> out_left = sortArray(left);
    vector<int> out_right = sortArray(right);
    out_left.push_back(nums[idx]);
    out_left.insert(out_left.end(), out_right.begin(), out_right.end());
    
    return out_left;
  }
private:
  int partition(vector<int>& nums, int pivotIdx){
    int idx(0);
    int pivot = nums[pivotIdx];
    for (int i=0; i != nums.size()-1; i++){
      //if (i== pivotIdx){continue;}
      if (nums[i] <= pivot){
        int tmp=nums[i];
        nums[i] = nums[idx];
        nums[idx] = tmp;
        idx++;
      }
      
    }
   
    int tmp = nums[idx];
   
    nums[idx] = pivot;
    nums[pivotIdx] = tmp;
    
    return idx;
  }
};

int main()
{
  vector<int> nums = {5,2,3,1,1};
  
  Solution sol;
  vector<int> out;
  out = sol.sortArray(nums);
  print(out);

  return 0;
}