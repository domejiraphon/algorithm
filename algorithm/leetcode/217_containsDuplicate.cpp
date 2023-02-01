#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_set>

using namespace std;
template <typename T>
void print(const vector<vector<T>> & vec)
{
    for(auto ele : vec)
    {
      for (auto x: ele){
        cout << x << ", ";
      }
      cout <<endl;
    }
    
}

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> Set;
    for (auto ele: nums){
      if (Set.find(ele) == Set.end()){
        Set.insert(ele);
      }
      else {return true;}
    }
    return false;
  }
};

int main()
{ 
  Solution* sol;
  vector<int> nums = {1,2,3,4};
  cout << sol -> containsDuplicate(nums)<< endl;

  nums = vector<int> {1,1,1,3,3,4,3,2,4,2};
  cout << sol -> containsDuplicate(nums)<< endl;
  return 0;
}