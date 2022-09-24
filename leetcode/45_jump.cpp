#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;
void print(vector<int> x){
  for (auto ele : x){
    cout << ele <<", ";
  }
  cout << endl;
}
class Solution {
public:
  int jump(vector<int>& nums) {
    vector<int> memo(nums.size(), INT_MAX);
    memo[0] = 0;
    for (int i=1; i < nums.size(); i++){
      for (int j=0; j < i; j++){
        if (j+ nums[j] >= i){
          memo[i] = min(memo[i], 1 + memo[j]);
        }
      }
    }
    return memo[nums.size() - 1];
  }
};

int main()
{ 
  vector<int> nums{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
  Solution sol;
  cout << sol.jump(nums) << endl;
 
  return 0;
}