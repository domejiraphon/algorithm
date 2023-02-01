#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
  string longestDiverseString(int a, int b, int c, char aa='a', char bb='b', char cc='c') {
    if (a < b){
      return longestDiverseString(b, a, c, bb, aa, cc);
    }
    if (b < c){
      return longestDiverseString(a, c, b, aa, cc, bb);
    }
    if (b == 0){
      return string(min(a, 2), aa);
    }
    int numA = min(a, 2); int numB = (a - numA >= b) ? 1 : 0;
    return string(numA, aa) + string(numB, bb) + longestDiverseString(a - numA, b - numB, c, aa, bb, cc);
  }
};