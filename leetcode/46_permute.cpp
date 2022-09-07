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
    int n=nums.size();
    vector<vector<int>> out;
    
    int sel;
    
    for (int i=0; i != n; i++){
      i = 2;
      sel = nums[i];
      /*
      vector<int> first_nums{nums.begin(), nums.begin()+i};
      vector<int> second_nums{nums.begin()+i+1, nums.end()};
      
      first_nums.insert(first_nums.end(), second_nums.begin(), second_nums.end());*/
      vector<int> first_nums{1, 2};
      for (int j=n-1; j != i-1; j--){
        vector<int> tmp;
        vector<int> first_vector{first_nums.begin(), first_nums.begin()+j};
        vector<int> second_vector{first_nums.begin()+j, first_nums.end()};
       
        tmp.insert(tmp.end(), first_vector.begin(), first_vector.end());
        tmp.push_back(sel);
        tmp.insert(tmp.end(), second_vector.begin(), second_vector.end());
        print_1d(tmp);
        out.push_back(tmp);
       
      }
      exit(0);
    
   
    }
     exit(0);
    return out;
    }
};
int main()
{ 
  vector<int> nums{1,2,3};
  Solution sol;
  vector<vector<int>>out = sol.permute(nums);
  print(out);
 
 
  return 0;
}