#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hash_table;
    vector <int> out;
    for (int i = 0; i != nums.size(); i++){
      if (hash_table.find(target - nums[i]) != hash_table.end()) {
        out.push_back(hash_table[target - nums[i]]);
        out.push_back(i);
      } 
      else 
        hash_table[nums[i]] = i;
    } 
    return out;
  }
};

int main()
{
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
