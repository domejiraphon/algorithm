#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int out=nums[0];
    for (int i=1; i != nums.size(); i++){
      out = out ^ nums[i];
    }
    return out;
  }
};
int main()
{ 
  vector<int> nums ={4,1,2,1,2};
  Solution sol;
  cout << (7^7) << endl;
  cout << (7^8^8) << endl;
  cout << (7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4) << endl;
  cout<< sol.singleNumber(nums) << endl;
  return 0;
}