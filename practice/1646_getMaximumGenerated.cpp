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
  int getMaximumGenerated(int n) {
    if (n==0) return 0;
    else if (n ==1)return 1;
    vector<int> out{0, 1};
    for (int i=2; i != n+1; i++){
      if (i %2==0){
        cout << (int) 4 /2;
        out.push_back(out[(int) i /2]);
      }
      else {
        out.push_back(out[(int) i /2] + out[(int) i /2+1]);
      }
    }
    return out[out.size()-1];
  }
};

int main()
{ 
  

  Solution sol;
 
  cout<< sol.getMaximumGenerated(7)<< endl;
  
  return 0;
}