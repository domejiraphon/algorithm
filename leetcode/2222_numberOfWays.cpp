#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;


class Solution {
public:
  long long numberOfWays(string s) {
    int count0(0);
    for (auto ele: s){
      count0 += ele == '0';
    }
    int count1 = s.size() - count0;
    long long way(0);
    
    if (count1 > 1){
      way += numWay(count1, 2) * numWay(count0, 1);
    }
    if (count0 > 1){
      way += numWay(count0, 2) * numWay(count1, 1);
    }
    return way;
  }
private:
  long long factorial(int n){
    if (n == 0){return 1;}
    long long out(1);
    for (int i=1; i <=n; i++){
      out *= i;
    }
    return out;
  }
  long long numWay(int a, int b) {
    cout << factorial(a) / (factorial(b) * factorial(a - b)) << endl;
    
    return factorial(a) / (factorial(b) * factorial(a - b));}
};

int main()
{ 
  
  Solution* sol;

  cout << sol -> numberOfWays("001101")<< endl;
  return 0;
}