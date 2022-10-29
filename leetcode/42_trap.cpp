#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> x){
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
}

class Solution {
public:
  int trap(vector<int>& height) {
    int n = height.size();
    int sum(0);
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i=1; i < n; i++){
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    rightMax[n-1] = height[n-1];
    for (int i= n - 2; i >=0; i--){
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    
    for (int i=1; i < n; i++){
      sum += min(leftMax[i], rightMax[i]) - height[i] ;
    }
    return sum;
  }
};

int main()
{ 
  Solution* sol;
  vector<int> height = {4,2,0,3,2,5};
  cout << sol -> trap(height) << endl;

  height = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << sol -> trap(height) << endl;
  return 0;
}