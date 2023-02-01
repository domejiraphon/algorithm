#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
void print(vector<int> x){
  for (auto row: x){
    cout << row <<", ";
  }
  cout << endl;
}

void print(deque<int> x){
  while (!x.empty()){
    cout << x.front()<< endl;
    x.pop_front();
  }
  cout << endl;
}

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> Q;
    int n = nums.size();
    
    for (int i=0; i< k; i++){
      while (!Q.empty() && nums[Q.back()] < nums[i]){
        Q.pop_back();
      }
      Q.push_back(i);
    }

    vector<int> out = {nums[Q.front()]};
    for (int i = k; i< n; i++){
      
      
      while (!Q.empty() && Q.front() <= i - k){
        Q.pop_front();
      }
      while (!Q.empty() && nums[Q.back()] < nums[i]){
        Q.pop_back();
      }
      Q.push_back(i);
      out.push_back(nums[Q.front()]);
      
    }
    
    return out;
  }
};

int main()
{ 
  
  Solution* sol = new Solution();
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  vector<int> out;
  out = sol ->maxSlidingWindow(nums, 3);
  print(out);

  nums = {1,-1};
  out = sol ->maxSlidingWindow(nums, 1);
  print(out);
  return 0;
}