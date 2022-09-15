#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

void print(vector<int> x){
 
    for (auto elem: x){
      cout << elem <<", ";}
    cout << endl;

  
}

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    map<int, int> hashTable;
    int count(0);
    int sum(0);
    for (int i=0; i != n; i++){
      sum += nums[i];
      if (sum == k){count++;}
      if (hashTable.find(sum - k) != hashTable.end()){
        count += hashTable[sum - k];
      }
      if (hashTable.find(sum) == hashTable.end()){hashTable[sum] = 1;}
      else {hashTable[sum]++;}
    }
    return count;
  }
};

int main()
{ 
  
  Solution* sol;
 
  
  vector<int> nums = {1, 1, 1};
  cout << sol -> subarraySum(nums, 2) << endl;


  nums = vector<int> {1, 2, 3};
  cout << sol -> subarraySum(nums, 3) << endl;
  
  return 0;
}