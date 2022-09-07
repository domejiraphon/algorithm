#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <cmath>
/*
https://leetcode.com/problems/rotate-image/
*/
using namespace std;
void print(const vector<vector<int>> matrix){
  for (auto row: matrix){
    for (auto elem: row){
      cout << elem <<", ";
    }
    cout << endl;
  }
}

void print_1d(const vector<int> matrix){
  for (auto elem: matrix){
    cout << elem <<", ";
  }
  cout << endl;
}

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> out{{nums[0]}};
   
    int sel;
    for (int i=1; i != nums.size(); i++){
      sel = nums[i];
      int n=out.size();
      vector<vector<int>> tmp =out;
      out.clear();
      for (int j=0; j != n; j++){
        for (int k=0; k != tmp[j].size()+1; k++){
          vector<int> first={tmp[j].begin(), tmp[j].begin()+k};
          vector<int> second={tmp[j].begin()+k, tmp[j].end()};
          vector<int> tmp2;
          tmp2.insert(tmp2.end(), first.begin(), first.end());
          tmp2.push_back(sel);
          tmp2.insert(tmp2.end(), second.begin(), second.end());

          out.push_back(tmp2);
        }
      }
      
    }
    return out;
    }
};

int main()
{ 
  vector<int> nums{1,2,3, 40};
  Solution sol;
  vector<vector<int>>out = sol.permute(nums);
  print(out);
 
 
  return 0;
}