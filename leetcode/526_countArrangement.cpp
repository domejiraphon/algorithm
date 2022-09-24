#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele :row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  int countArrangement(int n) {
    int count(0);
    vector<int> nums;
    for (int i=0; i != n; i++){nums.push_back(i + 1);}
    nums = {3,1,2};
    getPermutation(count, nums, 0);
    return count;
  }
private:
  void getPermutation(int& count, vector<int> nums, int low){
    if (low == nums.size()){
     
      count++; return;
    }
    for (int i=low; i != nums.size(); i++){
      swap(nums[low], nums[i]);
      
      if ((nums[low] % (i+1) ==0 ||(i +1) % nums[low] == 0) &&
          (nums[i] % (low+1) ==0 ||(low +1) % nums[i] == 0)){
        print(nums);
        cout << low <<",  "<< i;
        exit(0);
        getPermutation(count, nums, low+1);
      }  
    }
  }
};

int main()
{
  
  Solution* sol;
 
  cout << sol -> countArrangement(3)<<endl;
  cout << sol -> countArrangement(1)<<endl;
  return 0;
}