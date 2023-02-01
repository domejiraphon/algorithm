#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <cmath>
#include <vector>
#include <list>

using namespace std;
void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele: row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> res;
    if (m == 1){
      for (int i=0; i < n; i++){
        res.push_back(matrix[i][0]);
      }
    }
    else {
      BFS(matrix, 0, 0, 0, 0, n, m, res);
    }
    
    return res;
  }
private:
  void BFS(vector<vector<int>>& matrix, int row, int col, 
        int startRow, int startCol, int endRow, int endCol, 
        vector<int>& res){
    res.push_back(matrix[row][col]);
    matrix[row][col] = INT_MAX;
    
    
    if (row == startRow && col < endCol - 1 && matrix[row][col+1] != INT_MAX){
      BFS(matrix, row, col+1, startRow, startCol, endRow, endCol, res);
    }
    else if (startRow <= row && row < (endRow - 1) && col == (endCol - 1) && matrix[row+1][col] != INT_MAX){
      BFS(matrix, row + 1, col, startRow, startCol, endRow, endCol, res);
    }
    else if (row == (endRow - 1) && col > startCol && matrix[row][col-1] != INT_MAX){
      BFS(matrix, row, col - 1, startRow, startCol, endRow, endCol, res);
    }
    else if (startRow <= row && row < endRow && col == startCol && matrix[row-1][col] != INT_MAX){
      BFS(matrix, row - 1, col, startRow, startCol, endRow, endCol, res);
    }
    else if (row == (startRow + 1) && col == startCol && matrix[row-1][col] == INT_MAX){
      BFS(matrix, row, col + 1, startRow + 1, startCol + 1, endRow - 1, endCol - 1, res);
    }
  }
};

int main()
{
  Solution* sol;
  vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

  vector<int> out;
  //out = sol -> spiralOrder(matrix);
  //print(out);

  matrix = {{1}, {2}, {3}};
  out = sol -> spiralOrder(matrix);
  print(out);
}
