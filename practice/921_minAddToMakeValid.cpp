#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
public:
  int minAddToMakeValid(string s) {
    int count(0), num(0);
    for (auto ele: s){
      count = (ele == '(') ? count + 1: count - 1;
      if (count < 0){count++; num++;}
    }
    return num + count;
  }
};