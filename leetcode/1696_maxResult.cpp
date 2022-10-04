#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
void print(vector<int> path){
  for (auto ele: path){
    cout << ele << ", ";
  }
  cout << endl;
}

class Solution2 {
public:
  int maxResult(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> memo(nums.size(), -INT_MAX);
    int low;
    memo[0] = nums[0];
    for (int i=1; i < n; i++){
      low = (i-k >=0) ? i - k : 0;
      for (int j = low; j < i; j++){
        memo[i] = max(memo[i], memo[j] + nums[i]);
      }
    }
    return memo[nums.size() - 1];
  }
};

class Compare{
public:
  bool operator() (pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
  }
};
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    int n=nums.size();
    vector<int> memo(nums.size(), -INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> priorityQueue;
    int low;
    memo[0] = nums[0];
    priorityQueue.push({0, memo[0]});
    for (int i=1; i < n; i++){
      while(!priorityQueue.empty() && priorityQueue.top().first < i - k){
        priorityQueue.pop();
      }
      memo[i] = nums[i] + priorityQueue.top().second;
      priorityQueue.push({i, memo[i]});
    }
    print(memo);
    return memo[nums.size() - 1];
  }
};

int main()
{ 
  Solution* sol;
  vector<int> nums = {1,-1,-2,4,-7,3};
  cout << sol -> maxResult(nums, 2)<< endl;

  nums = {10,-5,-2,4,0,3};
  cout << sol -> maxResult(nums, 3) << endl;

  nums = {1,-5,-20,4,-1,3,-6,-3};
  cout << sol -> maxResult(nums, 2) << endl;


  return 0;
}