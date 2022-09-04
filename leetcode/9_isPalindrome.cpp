#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <list>
#include <string> 
#include <sstream>  
#include <iostream>  
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    string s = to_string(x);
    for (int i=0; i != s.length(); i++){
      if (s[i] != s[s.length() - i - 1]){
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution sol;
  cout << sol.isPalindrome(101);
  return 0;
}