#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int out(0);
    map<char, bool> visited;
    for (int i=0; i != s.size(); i++)
    {
      for (int j=i; j != s.size(); j++)
      {
        if (visited.find(s[j]) != visited.end()){break;}
        else {
          out = max(out, j - i + 1); 
          visited[s[j]] = true;
        
        }
      }
      visited.clear();
    }
    return out;
  }

  void print(map<char, bool> myMap)
  {
    cout << "{";
    for(const auto& elem : myMap)
      {
        cout << elem.first << ": " << elem.second <<", ";
      }
    cout << "}"<<endl;
  }
};

int main()
{ 
  string s;
  Solution sol;
  s = "aab";
  cout<< sol.lengthOfLongestSubstring(s) << endl;
 
  s="abcabcbb";
  cout<< sol.lengthOfLongestSubstring(s) << endl;
  
  s="bbbbb";
  cout<< sol.lengthOfLongestSubstring(s) << endl;
  
  s = "pwwkew";
  cout<< sol.lengthOfLongestSubstring(s) << endl;

  

  s = "dvdf";
  cout<< sol.lengthOfLongestSubstring(s) << endl;
  s = "ckilbkd";
  cout<< sol.lengthOfLongestSubstring(s) << endl;
  return 0;
}