#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

void print(vector<int> x){
  for (auto ele: x){
    cout << ele <<", ";
  }
   cout << endl;
}


class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> out;
    int n = nums.size() - 1;
    
    for (int i=0; i != n; i++){
      if (i == 0 || nums[i - 1] != nums[i]) {
      int low(i+1), high(n);
      while (low < high){
        int cur = nums[i] + nums[low] + nums[high];
        if (cur == 0){
          out.push_back(vector<int> {nums[i], nums[low++], nums[high--]});
          while (low < high && nums[low] == nums[low - 1]){
            low++;
          }
        }
        else if (cur > 0){high--;}
        else {low++;}
      }
      }
    }
    return out;
  }
};

int main()
{
  
  Solution sol;
  vector<vector<int>> out;
  vector<int> nums = {-1,0,1,2,-1,-4};
  //out = sol.threeSum(nums);
  
  vector<int> nums2 = {0,1,1};
  //out = sol.threeSum(nums2);
  
  vector<int> nums3 = {3,0,-2,-1,1,2};
  out = sol.threeSum(nums3);
  print(out);
  
  return 0;
}