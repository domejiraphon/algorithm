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

void print(vector<int> nums){
  for (auto row : nums){
      cout << row << ", ";
  }
  cout << endl;
}

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int count(0);
    vector<int> memo(nums.size(), 1);
    for (int i=0; i < nums.size(); i++){
     for (int j=0; j < i; j++){
      if (nums[i] > nums[j]){
        memo[i] = max(memo[i], memo[j] + 1);
        
      }
      count = max(memo[i], count);
     }
    }
    return count;
  }
};

int main()
{ 
  vector<int> nums = {10,9,2,5,3,7,101,18};
  Solution* sol;
  cout << sol ->lengthOfLIS(nums) << endl;

  nums = vector<int> {0,1,0,3,2,3};
  cout << sol ->lengthOfLIS(nums) << endl;

  nums = vector<int> {7,7,7};
  cout << sol ->lengthOfLIS(nums) << endl;
 
  return 0;
}