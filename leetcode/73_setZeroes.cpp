#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <unordered_set>
#include <stack>
#include <tuple>

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
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    unordered_set<int> row, col;
    for (int i=0; i < n; i++){
      for (int j = 0; j < m; j++){
        if (matrix[i][j] == 0){
          row.insert(i);
          col.insert(j);
        }
      }
    }
    for (auto it=row.begin(); it != row.end(); it++){
      for (int j=0; j <m; j++){
        matrix[*it][j] = 0;
      }
    }
    for (int i=0; i <n; i++){
      for (auto it=col.begin(); it != col.end(); it++){
        matrix[i][*it] = 0;
      }
    }
  }
};

int main()
{ 
  vector<vector<int>> matrix;
  Solution* sol;
  matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
  sol -> setZeroes(matrix);
  print(matrix);
  return 0;
}