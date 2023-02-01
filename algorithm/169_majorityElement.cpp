#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    map<int, int> count;
    for (int i=0; i != nums.size(); i++){
      if (count.find(nums[i]) == count.end()) 
      {
        count[nums[i]] = 1;
      }
      else 
      {
        count[nums[i]] += 1;
      }
    }
    int out=0, major;
    for (auto it = count.begin(); it != count.end(); it++)
    { 
      if (out < (it -> second)) 
      {
        out = it -> second;
        major = it -> first;
      }
    }
    return major;
  }
};

int main()
{ 
  vector<int> nums={2,2,1,1,1,2,2};
  Solution sol;
  
  cout<< sol.majorityElement(nums) << endl;
  vector<int> nums2={1};
  cout<< sol.majorityElement(nums2) << endl;
  return 0;
}