#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
  int findDuplicate(const vector<int>& nums) {
    cout << (7^7) << endl;
  cout << (7^8^8) << endl;
  cout << (7 ^ 1^ 7 ^2^3^4^5) << endl;
  cout << (7 ^ 1^ 7 ^2^3^4^5^6) << endl;
    exit(0);
  }
  
};

int main()
{
  vector<int> nums = {1,3,4,2,2};
  
  Solution sol;
  cout << sol.findDuplicate(nums)<<endl;
  nums = vector<int> {2,2};
  cout << sol.findDuplicate(nums)<<endl;
  return 0;
}