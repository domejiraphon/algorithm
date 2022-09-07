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
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int tmp;
    int n(matrix.size());
    for (int i=0; i != (int)n / 2; i++){
      for (int j=0; j != ceil(n / 2.); j++){
       
        tmp = matrix[i][j];
        matrix[i][j] = matrix[n-1-j][i];
        matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        matrix[j][n-1-i] = tmp;
      
      }
    }
    print(matrix);
  }
};
int main()
{ 
  vector<vector<int>> matrix{{1,2,3}, {4,5,6}, {7,8,9}};

  Solution sol;
  sol.rotate(matrix);
 
  return 0;
}