#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
class Solution2 {
public:
  int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> Set(nums.begin(), nums.end());
    int i(1);
    while (true){
      if (Set.find(i) == Set.end()){
        return i;
      }
      i++;
    }
  }
};
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n=nums.size();
    vector<int> idx;
    bool oneExist(false);
    for (int i=0; i<n; i++){
      if (nums[i] == 1){
        oneExist = true;
      }
      if (nums[i] <= 0 || nums[i] > n){
        idx.push_back(i);
      }
    }
   
    if (oneExist){
      for (auto ele: idx){
        nums[ele] = 1;
      }
    }
    else {return 1;}
    for (int i=0; i<n; i++){
      int cur = abs(nums[i]);
      if (cur < n){
          nums[cur] = - abs(nums[cur]);
      }
      if (cur == n){
          nums[0] = - abs(nums[0]);
      }
      
    }
    for (int i=1; i<n; i++){
      if (nums[i] > 0){return i;}
    }
      if (nums[0] > 0)
            return n;
    return n+1;
  }
};

int main()
{
  Solution* sol;
  vector<int> nums = {3,4,-1,1};
  cout << sol -> firstMissingPositive(nums)<< endl;
  nums = {3,4,-1,1,2, 14,10};
  //cout << sol -> firstMissingPositive(nums)<< endl;
}
