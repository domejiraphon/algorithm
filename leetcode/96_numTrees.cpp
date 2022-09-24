#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> memo(n + 1, 0);
    memo[0] = 1; memo[1] = 1; 
    for (int i=2; i < n+1; i++){
      for (int j = 0; j != i+1; j++){
        memo[i] += memo[j] * memo[i - j - 1];
      }
    }
    return memo[n];
  }
};

int main()
{ 
  
  Solution sol;

  cout << sol.numTrees(4)<< endl;

  return 0;
}