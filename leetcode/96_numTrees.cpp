#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
  if (n == 1){return 1;}
  else if (n == 2){return 2;}
  int tmp=2;
  for (int i=3; i != n+1; i++){
    if (i %2 == 0){
      tmp = 2*tmp+4;  
    }
    else {
      tmp = 2*tmp +1;
    }
  }
  return tmp;
  }
};

int main()
{ 
  
  Solution sol;

  cout << sol.numTrees(5)<< endl;

  return 0;
}