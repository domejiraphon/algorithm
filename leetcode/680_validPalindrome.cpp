#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    int low(0), high(s.size() - 1);
    while (low < high){
      if (s[low] == s[high]){
        low++; high--;
      }
      else {
        string tmp = s;
        string first = s.erase(low, 1);
        string second = tmp.erase(high, 1);
        return helper(first) || helper(second);
      }
    }
    return true;
  }
private:
  bool helper(string s){
    int low(0), high(s.size() - 1);
    while (low < high){
      if (s[low] == s[high]){
        low++; high--;
      }
      else {
        return false;
      }
    }
    return true;
  }
};

int main()
{ 
  
  Solution* sol;
  cout << sol -> validPalindrome("eddze")<< endl;
  //cout << sol -> validPalindrome("abca")<< endl;
  //cout << sol -> validPalindrome("aba")<< endl;
  return 0;
}