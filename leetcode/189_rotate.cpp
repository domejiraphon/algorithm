#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;
void print(vector<int> x){
  for (auto row: x){
    cout << row <<", ";
    
  }
  cout << endl;
}
class Solution2 {
public:
  void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    k = k % n;
    vector<int> left = {nums.begin(), nums.begin() + n - k};
    vector<int> right = {nums.begin() + n - k, nums.end()};
    for (int i=0; i < n; i++){
      if (i < k){
        nums[i] = right[i];
      }
      else {nums[i] = left[i -k];}
    }
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> nums;

  nums = {1,2,3,4,5,6,7,8};
  sol -> rotate(nums, 3);
  print(nums);
  return 0;
}