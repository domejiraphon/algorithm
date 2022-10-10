#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
void print(vector<int> x){
  for (auto elem: x){
    cout << elem <<", ";}
 
}

class Solution {
public:
  int twoEggDrop(int n) {
    vector<int> memo(n+1, INT_MAX);
    for (int i=0; i <= n ; i++){memo[i] = i;}
    for (int i=1; i <= n ; i++){
      for (int j=0; j < i; j++){
        memo[i] = min(memo[i], 1 + max(j-1, memo[i - j]));
      }
    
    }
    print(memo); exit(0);
    return memo[n];
  }
};

int main()
{ 
  
  Solution* sol;
  
  cout << sol -> twoEggDrop(100)<< endl;
  return 0;
}