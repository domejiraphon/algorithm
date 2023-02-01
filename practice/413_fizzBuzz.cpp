#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<string> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}


class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> out;
    for (int i=1; i <= n; i++){
      if (i % 15 == 0){out.push_back("FizzBuzz");}
      else if (i % 5 == 0){out.push_back("Buzz");}
      else if (i % 3 == 0){out.push_back("Fizz");}
      else {out.push_back(to_string(i));}
    }
    return out;
  }
};

int main()
{ 
  
  Solution* sol;
  vector<string> out;
  out = sol -> fizzBuzz(5);
  print(out);
  return 0;
}