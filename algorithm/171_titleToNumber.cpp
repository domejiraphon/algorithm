#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
      int n(0);
      for (auto ele: columnTitle){
        n *= 26;
        n += (int) ele - 'A' + 1;
      }
      return n;
    }
};

int main()
{ 
  Solution* sol;
  
  cout << sol -> titleToNumber("AB") << endl;
  return 0;
}