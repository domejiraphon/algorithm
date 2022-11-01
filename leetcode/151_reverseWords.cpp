#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    vector<string> out;
    string cur="";
    int n = s.size();
    for (int i=0; i < n; i++){
      if (s[i] != ' '){
        cur += s[i];
      }
      else{
        if (cur.size() !=0 ){
          out.push_back(cur);
          cur = "";
        }
        continue;}
    }
    if (cur.size() !=0 ){out.push_back(cur);}
    
    n=out.size();
    cur="";
    
    for (int i=n-1; i >= 0; i--){
      cur += out[i];
      if (i != 0){cur += " ";}
    }
    return cur;
  }
};

int main()
{
  Solution* sol;
  string s = "the sky is blue";
  cout << sol -> reverseWords(s)<< endl;

  return 0;
}