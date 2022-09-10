#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> out;
    int n = nums.size();
    for (int i=0; i !=n; i++){
      map<int, int> hash_table;
      vector<int> cur;
      for (int j=i+1; j <nums.size(); j++){
        if (hash_table.find(- nums[i] - nums[j]) != hash_table.end()){
          cur.push_back(nums[i]);
          cur.push_back(nums[j]);
          cur.push_back(- nums[i] - nums[j]);
          out.push_back(cur);
          cur.clear();
        }
        else {hash_table[nums[j]] = j;}
      }
      nums.erase(nums.begin());
    }
    return out;
  }
};

int main()
{
  
  Solution sol;
  vector<vector<int>> out;
  vector<int> nums = {-1,0,1,2,-1,-4};
  out = sol.threeSum(nums);
  print(out);

  vector<int> nums2 = {0,1,1};
  out = sol.threeSum(nums2);
  print(out);

  vector<int> nums3 = {0, 0, 0, 0};
  out = sol.threeSum(nums3);
  print(out);
  
  return 0;
}