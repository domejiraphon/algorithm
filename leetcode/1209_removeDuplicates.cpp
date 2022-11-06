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

class Solution2 {
public:
  string removeDuplicates(string s, int k) {
    size_t prev;
    do {
      prev = s.size();
      remove(s, k);
    } while (prev != s.size());
    return s;
  }
private:
  void remove(string& s, int k){
    stack<char> S;
    int i(0), n(s.size()), cur(0);
    
    while (i < n){
      if (!S.empty()){
        cur = (S.top() == s[i]) ? cur + 1: 1;
      }
      else {
        cur++;
      }
      S.push(s[i]);
      if (cur == k){
        while (cur-- > 0){S.pop();}
      }
      i++;
    }
    s.clear();
    while (!S.empty()){
      s = S.top() + s;
      S.pop();
    }
  }
};

class Solution {
public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> S;
    int i(0), n(s.size());
    while (i < n){
      if (!S.empty()){
        if (S.top().first == s[i]){
          S.push({s[i], S.top().second + 1});
        }
        else {
          S.push({s[i], 1});
        }
      }
      else {
        S.push({s[i], 1});
      }
      if (S.top().second == k){
        int cur= S.top().second;
        while (cur-- > 0){
          S.pop();
        }
      }
      i++;
    }
    s.clear();
    while (!S.empty()){
      s = S.top().first + s;
      S.pop();
    }
    return s;
  }
};

int main()
{ 
  Solution* sol = new Solution();
  cout << sol -> removeDuplicates("pbbcggttciiippooaais", 2) << endl;
  cout << sol -> removeDuplicates("abcd", 2) << endl;
  cout << sol -> removeDuplicates("aaabc", 2) << endl;
  return 0;
}