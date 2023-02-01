#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    remove(s); 
    remove(t);
    return (t == s);
  }
private:
  void remove(string &s){
    stack<char> S;
    for (auto ele: s){
      if (ele == '#' && !S.empty()){
        S.pop();
      }
      else if (ele == '#' && S.empty()){
        continue;
      }
      else{
        S.push(ele);
      }
    }
    s.clear();
    while (!S.empty()){
      s = string(1, S.top()) + s;
      S.pop();
    }
  }
};

int main()
{ 
  Solution* sol;
  cout << sol -> backspaceCompare("ab#c", "ad#c")<< endl;
  cout << sol -> backspaceCompare("ab###", "c#d#")<< endl;
  cout << sol -> backspaceCompare("a#c", "b")<< endl;

  return 0;
}