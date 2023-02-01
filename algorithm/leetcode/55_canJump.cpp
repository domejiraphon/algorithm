/* 55. Jump Game
You are given an integer array nums. 
You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/
class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n=nums.size();
    vector<bool> canReach(n, false);
    canReach[n-1] = true;
    for (int i=n-2; i>=0; i--){
      for (int step=0; step<=nums[i] && !canReach[i]; step++){
        if (i+step > n-1){canReach[i] = true;}
        else {canReach[i] = canReach[i+step];}
      }
    }
    return canReach[0];
  }
};