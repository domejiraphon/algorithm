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
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

bool sortby(const vector<int> &a,
              const vector<int> &b){
  return  (a[1]*a[0] > b[1]*b[0]);}

class Solution {
public:
  int maxArea(vector<int>& height) {
    int left(0), right(height.size()-1);
    int maxA(0);
    while (left < right){
      if (height[left] < height[right]){
        maxA = max(maxA, (right - left)* height[left]);
        left++;
      }
      else{
        maxA = max(maxA, (right - left)* height[right]);
        right--;
      }
    }
    return maxA;
  }
};

int main()
{
  vector<int> nums = {1,8,6,2,5,4,8,3,7};
  
  Solution sol;

  cout<< sol.maxArea(nums)<<endl;
  nums = vector<int> {1,2,1};
  cout<< sol.maxArea(nums)<<endl;
  return 0;
}