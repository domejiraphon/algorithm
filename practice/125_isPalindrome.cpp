#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    char prefix, suffix;
    int idx = s.size();
    for (int i=0; i != s.size(); i++){
      while ((!isalnum(s[i]))) {
        i++;
        if (i > s.size()) {
          return true;
        }
      }
      while ((!isalnum(s[idx - 1]))) {
        idx--;}
        if (idx < 0) {
          return true;
      }
      if (isalpha(s[i]) && isalpha(s[idx - 1])) {
        if (tolower(s[i]) == tolower(s[idx - 1])) {
          idx--; continue;
        }
        return false;
      }
      else if (isdigit(s[i]) && isdigit(s[idx - 1])) {
        if (s[i] == s[idx - 1]) {
          idx--; continue;
        }
        return false;
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
  string s="A man, a plan, a canal: Panama";
  Solution sol;
  //cout<< sol.isPalindrome(s) << endl;
  s = "race a car";
  //cout<< sol.isPalindrome(s) << endl;
  s = "0P";
  cout<< sol.isPalindrome(s) << endl;
  return 0;
}