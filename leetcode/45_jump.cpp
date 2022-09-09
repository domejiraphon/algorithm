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
class Solution {
public:
  int jump(vector<int>& nums) {
    int furthest(0);
    int prev(0);
    int count(0);
    for (int i=0; i != nums.size(); i++){
      if (furthest >= (nums.size()-1)) {break;}
      if (furthest < i+nums[i])
        {furthest = i+nums[i];
        if (prev < furthest){
          count++;
        }
        cout << furthest << " ";
        prev = furthest;
        }
    }
    return count;
  }
};

int main()
{ 
  vector<int> nums{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
  Solution sol;
  sol.jump(nums);
  cout << endl;

  return 0;
}