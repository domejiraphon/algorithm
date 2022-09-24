#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;

void print(map<char, vector<int>> hash){
  for (auto it=hash.begin(); it != hash.end(); it++){
    cout << it -> first << ":";
    for (auto ele: it -> second){
      cout << ele<< ", ";
    }
    cout << endl;
  }
}
class Solution {
public:
  string removeDuplicateLetters(string s) {
    stack<char> S;
    
    for (int i=0; i < s.size(); i++){
      string sub ={s.begin() + i, s.end()};
      if (!S.empty()){
        char prev = S.top();
        //cout << prev <<", "<< s[i]<< endl;
        if (prev > s[i] && sub.find(prev) != string::npos){
          S.pop();
        }
      }
      S.push(s[i]);
     
    }
    string out="";
    while (!S.empty()){
      out = S.top() + out;
      S.pop();
    }
    return out;
  }
};

int main()
{ 
  
  Solution* sol;

  cout << sol -> removeDuplicateLetters("cbacdcbc") << endl;
  
  cout << sol -> removeDuplicateLetters("bcabc") << endl;
  return 0;
}