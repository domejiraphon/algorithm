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
  int findKthLargest(vector<int>& nums, int k){return helper(nums, nums.size()-k);}
private:
  int helper(vector<int>& nums, int k) {
    int pivot = nums[0];
    int idx = partition(nums, nums[nums.size()-1]);
   
    if (idx == k){return nums[k];}
    else if (k < idx){
      nums = {nums.begin(), nums.begin()+idx};
      return helper(nums, k);
    }
    else {
      nums = {nums.begin()+idx+1, nums.end()};
      return helper(nums, k-idx-1);
    }
  }
  int partition(vector<int>& nums, int pivot){
    int idx(0);
    for (int i=0; i != nums.size()-1; i++){
      if (nums[i] <= pivot){
        int tmp=nums[i];
        nums[i] = nums[idx];
        nums[idx] = tmp;
        idx++;
      }
    }
    int tmp = nums[idx];
    nums[idx] = pivot;
    nums[nums.size()-1] = tmp;
    return idx;
  }
};

int main()
{
  vector<int> nums={1,2,3,6,5};
  
  Solution sol;
  
  cout << sol.findKthLargest(nums, 1) << endl;

  return 0;
}