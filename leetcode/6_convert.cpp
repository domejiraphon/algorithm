#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
void print(vector<string> x){
  for (auto v: x){
    cout << v<<endl;
  }
  cout << endl;
}

class Solution {
public:
  string convert(string s, int numRows) {
    vector<string> out(numRows);
    int every=2*numRows - 2;
    int row_used(0);
    for (int i = 0; i < s.size(); i+= every){
      vector<string> tmp(numRows);
      string sub;
      if (i+every > s.size()){
        sub = s.substr(i);
        row_used = (sub.size() > numRows) ?  numRows : sub.size();
      }
      else{
        sub = s.substr(i, every);
        row_used = numRows;
      }
     
      for (int j = 0; j < sub.size(); j++){
        if (j < numRows)
          tmp[j] = string(1, sub[j]) + string(numRows-1-j, ' '); 
        else {
          tmp[every - j] += string(1, sub[j])+ string(every-j-1, ' ');
        }
      }
      tmp[numRows-1] += string(numRows-1, ' ');
      for (int j=0; j < row_used; j++){out[j] += tmp[j];}
      tmp.clear();
     
    }
    string tmp2;
    for (auto elem: out){
      tmp2 += elem + string(1, '\n');
    }
    return tmp2;
  }
};

int main()
{ 
  string s="PAYPALISHIRING";
  Solution sol;
  cout << sol.convert(s, 4) << endl;
 
  return 0;
}