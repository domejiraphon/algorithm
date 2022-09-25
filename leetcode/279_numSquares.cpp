#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cmath>

using namespace std;

void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}
class Solution {
public:
  int numSquares(int n) {
    vector<int> pos;
    for (int i=1; i <= n; i++){
      if (pow(i, 2) <= n){
        pos.push_back(pow(i, 2));
      }
    }

    vector<int> memo(n+1, INT_MAX);
    memo[0] = 0;
    memo[1] = 1;
    for (int i=2; i <= n; i++){
      for (int j=0; j<pos.size() &&pos[j] <= i; j++){
        memo[i] = min(memo[i], 1 + memo[i - pos[j]]);
      }
    }
    print(memo);
    return memo[n];
  }
};

int main()
{ 
  Solution* sol;


  cout << sol -> numSquares(13)<< endl;
  return 0;
}