#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> memo(n, vector<int>(m, 0));
    int num(INT_MIN);
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if ((i==0 || j == 0)&& matrix[i][j] == '1'){memo[i][j] = 1;}
        else if (matrix[i][j] == '1'){
          if (memo[i-1][j-1] >=1 &&
              memo[i][j-1] >= 1 &&
              memo[i-1][j] >= 1){
            memo[i][j] = min(min(memo[i-1][j-1], memo[i][j-1]), memo[i-1][j]) + 1;
          }
          else {memo[i][j] = 1;}
        }
        num = max(num, memo[i][j]);
      }
    }
    return pow(num, 2);
  }
};

int main()
{
  Solution* sol;
  vector<vector<char>> matrix;
  matrix = {{'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','1','1','1'}};

  cout << sol ->maximalSquare(matrix)<< endl;
}
