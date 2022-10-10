#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <unordered_set>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;
void print(set<int> x){
  for (auto it= x.begin(); it != x.end(); it++){
    cout << *it <<", ";
    }cout  << endl;
 
}
void print(vector<int> x){
  for (auto it= x.begin(); it != x.end(); it++){
    cout << *it <<", ";}
 
}


class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> memo(m, vector<vector<int>> (n, vector<int> (maxMove + 1, -INT_MAX)));
    return helper(m, n, maxMove, startRow, startColumn, memo);
  
  }
private:
  int helper(int m, int n, int maxMove, int startRow, int startColumn, 
            vector<vector<vector<int>>>& memo){
    int mod = pow(10, 9) + 7;
    if (startRow < 0 || startRow == m || startColumn < 0 || startColumn == n){
      return 1;
    }
    if (maxMove ==0){return 0;}
    if (memo[startRow][startColumn][maxMove] != -INT_MAX){return memo[startRow][startColumn][maxMove];}
    
    memo[startRow][startColumn][maxMove] = 
        helper(m, n, maxMove - 1, startRow - 1, startColumn, memo) % mod + 
        helper(m, n, maxMove - 1, startRow, startColumn - 1, memo) % mod +
        helper(m, n, maxMove - 1, startRow + 1, startColumn, memo) % mod +
        helper(m, n, maxMove - 1, startRow, startColumn + 1, memo) % mod;
    return memo[startRow][startColumn][maxMove];
  }
};

int main()
{ 
  
  Solution* sol;
  cout << sol -> findPaths(2, 2, 2, 0, 0)<< endl;
  cout << sol -> findPaths(1, 3, 3, 0, 1)<< endl;

  
  return 0;
}