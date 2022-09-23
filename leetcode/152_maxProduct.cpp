#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(unordered_map<string, int> hashTable){
  for (auto it=hashTable.begin(); it != hashTable.end(); it++){
    cout << it -> first << ", "<< it -> second<< endl;
  }
  cout << endl;
}

void print(vector<vector<int>> nums){
  for (auto row : nums){
    for (auto ele: row){
      cout << ele << ", ";
    }
    cout << endl;
  }
  
}

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int _min(nums[0]), _max(nums[0]), out(nums[0]);
    for (int i=1; i != nums.size(); i++){
      int tmp = max(nums[i],  max(_max * nums[i], _min * nums[i]));
      _min = min(nums[i],  min(_max * nums[i], _min * nums[i]));

      _max = tmp;
      out = max(out, max(_max, _min));

    }
    return out;
  }
};

int main()
{ 
  vector<int> nums = {-1, 2, 2, -3, -4};
  Solution* sol;
  cout << sol -> maxProduct(nums) << endl;
 
  return 0;
}