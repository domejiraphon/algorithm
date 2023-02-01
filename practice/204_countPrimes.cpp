#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 1){return 0;}
    bool notFound(true);
    int count(0);
    for (int i=2; i < n; i++){
      for (int j=2; j < sqrt(i); j++){
        if (i % j == 0){notFound=false; break;}
      }
      if (notFound){count++;}
      notFound = true;
    }
    return count;
  }
};

int main()
{
  Solution* sol;
  cout << sol -> countPrimes(100)<< endl;
}
