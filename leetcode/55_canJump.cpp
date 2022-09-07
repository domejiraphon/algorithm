#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <cmath>
/*
https://leetcode.com/problems/rotate-image/
*/
using namespace std;
void print_1d(const vector<bool> matrix){
  for (auto elem: matrix){
    cout << elem <<", ";
  }
  cout << endl;
}
class Solution {
public:
  bool canJump(vector<int>& nums) {
    vector<bool> can_jump(nums.size(), false);
   
    can_jump[nums.size()-1] = true;
     
    for (int i=nums.size()-2; i != -1; i--){
      bool jump(false);
      for (int j=0; j != nums[i]+1; j++){
        if (i+j >= nums.size()-1){ jump=true; break;}
        jump = jump || can_jump[i+j];
      }
      
      can_jump[i] = jump;
      
    }
    return can_jump[0];
  }
};
int main()
{ 
  vector<int> nums{2,3,1,1,4};
  Solution sol;
  cout<< sol.canJump(nums);

  nums = vector<int> {3,2,1,0,4};
  cout<< sol.canJump(nums);
 
 
  return 0;
}