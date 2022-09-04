#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int count(0);
    s.erase(s.find_last_not_of(" \n\r\t")+1);
    while (s[s.length()-1] != ' ') {
      count++;
      if (s.length() == 1)
        break;
      s = s.substr(0, s.length()-1);
   
    }
    return count;
  }
};

int main()
{
  //string s("Hello World");
  string s("a");
  Solution sol;
  cout << sol.lengthOfLastWord(s) << endl;
  return 0;
}