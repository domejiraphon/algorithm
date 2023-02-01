#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
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
  int countSquares(vector<vector<int>>& matrix) {
    vector<vector<int>> memo (matrix.size(), vector<int> (0, matrix[0].size()));
    for (int i=0; i < min(matrix.size(), matrix[0].size()); i++){
      for (int square=0; square < i; square++){
        
      }
    }
  }
};

int main()
{ 
  
  Solution* sol;
  vector<vector<int>> matrix = {{0,1,1,1},
                                {1,1,1,1},
                                {0,1,1,1}};

  cout << sol -> countSquares(matrix) << endl;
  return 0;
}