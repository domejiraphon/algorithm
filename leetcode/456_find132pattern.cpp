#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;
class myComparator{
public:
  int operator() (pair<int, int>& a, pair<int, int>& b){return a.second < b.second;}
};

class Solution2 {
public:
  bool find132pattern(vector<int>& nums) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparator> maxHeap, tmp;
    int n=nums.size();
    for (int i=0; i< n; i++){
      if (i >= 1 && nums[i] == nums[i - 1]){continue;}
      maxHeap.push({i, nums[i]});
    }
    tmp = maxHeap;
    pair<int, int> maxVal, rightVal;
    while (tmp.size() >= 3){
      maxVal = maxHeap.top();
      maxHeap.pop();
    
      while (!maxHeap.empty()){
        pair<int, int> cur = maxHeap.top();
        if (cur.first > maxVal.first && maxVal.second > cur.second){
          rightVal = cur; break;
        }
        else {
          maxHeap.pop();
        }
      }
      
      while (!maxHeap.empty()){
        pair<int, int> cur = maxHeap.top();
        if (cur.first < rightVal.first && 
            cur.first < maxVal.first &&
            rightVal.second > cur.second){
         
          return true;
        }
        else {
          maxHeap.pop();
        }
      }
      tmp.pop();
      maxHeap = tmp;
    }
    
    return false;
  }
};

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    int left(INT_MAX);
    for (int i=0; i < n; i++){
      left = min(left, nums[i]);
      for (int j=i+1; j < n; j++){
        if (nums[j] < nums[i] && left < nums[j]){
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> nums;

  nums = {1,2,3,4};
  cout << sol -> find132pattern(nums)<< endl;

  nums = {3,1,4,2};
  cout << sol -> find132pattern(nums)<< endl;
  
  nums = {1, 0, 1, -4, -3};
  cout << sol -> find132pattern(nums)<< endl;
  
  nums = {1,3,2,4,5,6,7,8,9,10};
  cout << sol -> find132pattern(nums)<< endl;
  return 0;
}