#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
  int min_length=200;
  string out;
  if (strs.size() == 1){
    return strs[0];
  }
  for (int i=0; i != strs.size(); i++){
    if (min_length > strs[i].size()){
      min_length = strs[i].size();
    }
  }
  
  for (int i=0; i != min_length; i++){
    char com(strs[0][i]);
    int found=0;
    for (int j=1; j != strs.size(); j++){
      char cur(strs[j][i]);
      if (cur != com){
        found = 0;
        break;
      }
      else
        found = 1;
    }

    if (found)
      out.push_back(com);
      break
  }
  return out;
  }
};

int main()
{
  vector<string> strs1, strs2;
  strs1.push_back("flight");
  strs1.push_back("flow");
  strs1.push_back("flight");
  strs2.push_back("dog");
  strs2.push_back("racecar");
  strs2.push_back("car");
  Solution sol;
  cout << sol.longestCommonPrefix(strs1) <<endl;
  cout << sol.longestCommonPrefix(strs2)<<endl;
  return 0;
}