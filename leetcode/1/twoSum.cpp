// overloading operators example
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> out;
    for (int i=0; i != nums.size(); i++) {
      for (int j=i+1; j != nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          out.push_back(i);
          out.push_back(j);
          return out;
        }
      }
    }
    return out;
  }
};

int main () {
  vector<int> g1;
  g1.push_back(3);
  g1.push_back(2);
  g1.push_back(4);
  Solution sol;
  vector<int> out;
  out = sol.twoSum(g1, 6);
  for (auto i=out.begin(); i != out.end(); i++) {
    cout << *i << endl;
  }
  return 0;
}