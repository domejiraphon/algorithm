#include <iostream>
#include <iterator>
#include <unordered_set>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    size_t n = nums.size();
    unordered_set<int> S;
    int count(0);
    for (auto ele: nums){
      if (!S.count(ele) && ele != 0){
        S.insert(ele);
        count++;
      }
    }
    return count;
  }
};

int main()
{
  Solution* sol;
  vector<int> nums = {1, 0, 5, 3, 5};
  cout << sol -> minimumOperations(nums) << endl;
  return 0;
}