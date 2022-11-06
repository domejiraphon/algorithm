#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
void print(stack<char> S){
  while (!S.empty()){
    cout << S.top() << endl;
    S.pop();
  }
}

class Solution {
public:
  bool validWordAbbreviation(string word, string abbr) {
    int i(0), n(abbr.size());
    int ptr(0), nWord(word.size());
    while (i < n){
      if (isdigit(abbr[i])){
        int count(0);
        if (abbr[i] == '0'){return false;}
        while (i < n && isdigit(abbr[i])){
          count = 10 * count;
          count += (int)(abbr[i++] - '0');
        }
        i--;
        ptr += count;
        if (ptr > nWord){return false;}
      }
      else {
        if (ptr < nWord && word[ptr] != abbr[i]){return false;}
        ptr++; 
      }
      i++;
    }
    return (ptr == word.size() && i == abbr.size()) ? true: false;
  }
};

int main()
{ 
  Solution* sol = new Solution();
  cout << sol -> validWordAbbreviation("internationalization", "i12iz4n");
  return 0;
}