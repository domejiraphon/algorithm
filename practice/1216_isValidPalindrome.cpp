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
  vector<vector<int>> memo;
public:
  bool isValidPalindrome(string s, int k) {
    memo.resize(s.length(), vector<int>(s.length(), -1));
    int num = isValidPalindrome(s, 0, s.length() - 1);
    return (num <= k) ? true : false;
  }
private:
  int isValidPalindrome(string &s, int i, int j){
    if (i == j){return 0;}
    if (i == j + 1){return s[i] != s[j];}
    
    if (memo[i][j] != -1){return memo[i][j];}
    int out;
    if (s[i] == s[j]){
      out = isValidPalindrome(s, i+1, j-1);
    }
    else {
      out = 1 + min(isValidPalindrome(s, i+1, j), isValidPalindrome(s, i, j-1));
    }
    memo[i][j] = out;
    return out;
  }
};


class Solution {
public:
  bool isValidPalindrome(string s, int k) {
    map<pair<int, int>, bool> hash;
    return check(s, k, 0, s.size() - 1, hash);
  }
private:
  bool check(string s, int k, int start, int end, 
             map<pair<int, int>, bool> hash){
    if (k < 0){return false;}
    if (start > end){return true;}
    if (hash.count({start, end})){
      return hash[{start, end}];
    }
    bool out;
    if (s[start] == s[end]){
      out = check(s, k, start + 1, end - 1, hash);
    }
    else {
      out = check(s, k - 1, start + 1, end, hash) ||
            check(s, k - 1, start, end - 1, hash);
    }
    hash[{start, end}] = out;
    return out;
  }
};