#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(vector<int>& nums){
  for (auto ele: nums){
    cout << ele <<", ";
  }
  cout << endl;
}

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    for (int i=0; i != nums.size()-1; i++){
      if (i %2==1 && nums[i] < nums[i+1]){
        swap(nums[i], nums[i+1]); 
      }
      else if (i % 2 ==0 && nums[i] > nums[i+1]){
        swap(nums[i], nums[i+1]); 
      }
    }
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> nums={3, 5, 6, 2, 1, 4, 9, 10};
  sol -> wiggleSort(nums);
  print(nums);
  return 0;
}