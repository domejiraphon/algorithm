#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(vector<int> memo){
  for (auto ele: memo){
    cout << ele << ", "; 
  }
  cout << endl;
}

class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> out;
    unordered_map<int, int> HashTable;
    int sum(0);
    for (int i = 0; i != nums.size(); i++){
      if (nums[i] % 2 == 0){HashTable[i] = nums[i]; sum += nums[i];}
    }
    for (int i = 0; i != queries.size(); i++){
      nums[queries[i][1]] += queries[i][0];
      if (nums[queries[i][1]] %2 == 0){
        sum += nums[queries[i][1]];
      }
      if (HashTable[queries[i][1]] % 2 == 0){
        sum -= HashTable[queries[i][1]];
      }
      
      HashTable[queries[i][1]] = nums[queries[i][1]];
      out.push_back(sum);
    }
    return out;
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> nums = {1, 2, 3, 4};
  vector<vector<int>> queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
  vector<int> out;
  out = sol -> sumEvenAfterQueries(nums, queries);
  print(out);

  nums = vector<int> {5,5,4};
  queries = vector<vector<int>> {{0, 1}, {1, 0}, {4, 1}};
  out = sol -> sumEvenAfterQueries(nums, queries);
  print(out);
 
  nums = vector<int> {3, 2};
  queries = vector<vector<int>> {{4, 0}, {3, 0}};
  out = sol -> sumEvenAfterQueries(nums, queries);
  print(out);
 
  
  return 0;
}