#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}
class Compare{
public:
  int operator() (int a, int b){
    return a < b;}
};
class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int, vector<int>, Compare> maxHeap;
    for (auto ele: stones){
      maxHeap.push(ele);
    }

    while (maxHeap.size() > 1){
      int x = maxHeap.top(); maxHeap.pop();
      int y = maxHeap.top(); maxHeap.pop();
      if (x == y){continue;}
      else if (x > y){
        maxHeap.push(x - y);
      }
    }
    return maxHeap.empty() ? 0: maxHeap.top();
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> stones = {2,7,4,1,8,1};
  cout << sol -> lastStoneWeight(stones)<< endl;

  stones = {1};
  cout << sol -> lastStoneWeight(stones)<< endl;
  return 0;
}