#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<string> S;
    string out;
    
    for (int i=0; i < s.size(); i++){
      if (s[i] != ']'){
        S.push(string(1, s[i]));
      }
      else {
        string cur;
        while (S.top() != "["){
          cur = S.top() + cur;
          S.pop();
        }

        S.pop();
        int base=1;
        int rep = 0;
        // get the number k
        while (!S.empty() && isdigit(S.top()[0])) {
            rep += (S.top()[0] - '0') * base;
            S.pop();
            base *= 10;
        }
       

        string repeat;
        for (int j=0; j < rep; j++){
          repeat += cur;
        }
        if (S.empty()){
          out += repeat;
        }
        else {
          S.push(repeat);
        }
      }
    }
    string res="";
    while (!S.empty()){
      res = S.top() + res;
      S.pop();
    }
    return out + res;
  }
};

int main()
{ 
  Solution sol;
  cout<< sol.decodeString("3[ac]")<<endl;
  cout<< sol.decodeString("3[a]2[bc]")<< endl;
  cout<< sol.decodeString("3[a2[c]]")<< endl;
  cout<< sol.decodeString("ef10[leetcode]")<< endl;
 
  return 0;
}