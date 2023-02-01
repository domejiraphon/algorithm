#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int n=haystack.size();
    int m=needle.size();
    for (int i=0; i <= n - m; i++){
      if (haystack.substr(i, m) == needle){
        return i;
      }
    }
    return -1;
  }
};
int main()
{
  Solution* sol;
  cout << sol -> strStr("sadbutsad", "sad")<< endl;
  cout << sol -> strStr("a", "a")<< endl;
  cout << sol -> strStr("leetcode", "leeto")<< endl;
  return 0;
}