#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

void print(vector<int> x){
  for (auto ele: x){
    cout << ele <<", ";
  }
   cout << endl;
}

class Solution2 {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> S;
    int n = nums.size();
    for (int i=0; i !=n; i++){
      map<int, int> hash_table;
      for (int j=i+1; j <nums.size(); j++){
        if (hash_table.find(- nums[i] - nums[j]) != hash_table.end()){
          vector<int> cur;
          cur.push_back(nums[i]);
          cur.push_back(nums[j]);
          cur.push_back(- nums[i] - nums[j]);
          sort(cur.begin(), cur.end());
          S.insert(cur);
          
          //out.push_back(cur);
        }
        else {hash_table[nums[j]] = j;}
      }
      //nums.erase(nums.begin());
    }
    vector<vector<int>> out={S.begin(), S.end()};
    return out;
  }
};



class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    map<vector<int>, bool> hashTable;
    vector<vector<int>> out;
    //set<vector<int>> S;
    for (int i=0; i != nums.size() - 1; i++){
      int low(i+1), high(nums.size() - 1);
      while (low < high){
        if (nums[i] + nums[low] + nums[high] == 0){
          vector<int> cur;
          cur.push_back(nums[i]); cur.push_back(nums[low]); cur.push_back(nums[high]); 
          high--;
          if (hashTable.find(cur) == hashTable.end()){out.push_back(cur); hashTable[cur] = true;}
          
          //S.insert(cur); 
        }
        else if (nums[i] + nums[low] + nums[high] > 0){high--;}
        else {low++;}
      }
    }
    return out;
  }
};

int main()
{
  
  Solution sol;
  vector<vector<int>> out;
  vector<int> nums = {-1,0,1,2,-1,-4};
  //out = sol.threeSum(nums);
  
  vector<int> nums2 = {0,1,1};
  //out = sol.threeSum(nums2);
  
  vector<int> nums3 = {3,0,-2,-1,1,2};
  out = sol.threeSum(nums3);
  print(out);
  
  return 0;
}