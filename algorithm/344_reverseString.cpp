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
  void reverseString(vector<char>& s) {
    int low(0), high(s.size() - 1);
    while (low < high){
      swap(s[low++], s[high--]);
    }
  }
};