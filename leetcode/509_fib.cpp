#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <sstream>  // for string streams
#include <string> 
using namespace std;
class Solution {
public:
  int fib(int n) {
    if (n==0){ return 0;}
    else if (n==1){return 1;}
    vector<int> out {0, 1};
    for (int i =2; i != n+1; i++){
      int tmp = out[1];
      out[1] += out[0];
      out[0] = tmp;
    }
    return out[1];
  }
};

int main()
{ 
 
  Solution sol;
 
  cout<< sol.fib(5)<< endl;
  
  return 0;
}