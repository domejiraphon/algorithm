#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;


class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    int i(0), n(nums.size());
    int up, monotone(false);
    int prev;
    for (int i=0; i < n - 1; i++){
      up = (nums[i] < nums[i+1]) ? 1 : (nums[i] > nums[i+1]) ? -1 : 0;
      if (i == 0){prev = up;}
      if  (prev >= 0 && up < 0){
        return false;
      }
      else if (prev <= 0 && up > 0){
        return false;
      }
    }
    return true;
  }
};

int main()
{ 
  
  Solution* sol;

  return 0;
}