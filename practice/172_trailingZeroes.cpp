#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;

class Solution2 {
public:
  int trailingZeroes(int n) {
    if (n == 0){return 0;}
    int fac(1);
    for (int i=1; i<=n; i++){
      fac *= i;
    }
    int count(0);
    while (fac % 10 == 0){
      count++;
      fac = (int) fac /10;
    }
    return count;
  }
};

class Solution {
public:
  int trailingZeroes(int n) {
    int count(0);
    int div(5);
    while (div <= n){
      count += (int) n / div;
      div *= 5;
    }
    return count;
  }
};

int main()
{ 
  Solution* sol;
  cout << sol -> trailingZeroes(3) << endl;
  cout << sol -> trailingZeroes(5) << endl;
  cout << sol -> trailingZeroes(30) << endl;

  return 0;
}