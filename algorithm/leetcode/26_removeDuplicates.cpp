#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int idx(0);
      for (int i=0; i != nums.size() -1; i++){
        if(nums[i]==nums[i+1])
          continue;
        else {
          nums[idx+1]=nums[i+1];
          idx++;
        }
      }
      
      return idx+1;
    }
    void print(const vector<int>& nums){
      for (auto i: nums)
        cout << i << " ";
      cout << endl;
    }
};

int main()
{
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  Solution sol;
  cout << sol.removeDuplicates(nums) << endl;
  sol.print(nums);
  return 0;
}