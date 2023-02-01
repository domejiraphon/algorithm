#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int idx(0);
    for (int i=0; i != nums.size(); i++){
        if(nums[i]==val)
          continue;
        else {
          nums[idx]=nums[i];
          idx++;
        }
    }
    return idx;
  }
  void print(const vector<int>& nums){
    for (auto i: nums)
      cout << i << ", ";
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
  nums.push_back(2);
  Solution sol;
  cout << sol.removeElement(nums, 2) << endl;
  sol.print(nums);
  return 0;
}