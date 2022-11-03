#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;
void print(stack<string> s){
  while (!s.empty()){
    cout << s.top()<< endl;
    s.pop();
  }
}

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> S;
    int i(0), n(path.size());
    while (i < n){
      if (!S.empty()){
        string prev = S.top();
        if (prev[prev.size() - 1] == '/' && path[i] == '/'){
          i++;
          continue;}
        else if (path[i] == '.' && path[i - 1] == '/'){
          string dot;
          while (i < n && path[i] == '.'){
            dot += path[i];
            i++;
          }
          i--;
          if (dot == ".." && i ==  n -1){S.pop();}
          else if (dot == ".." && i < n - 1 && path[i+1] == '/'){S.pop();}
          else if (dot == "." && i < n - 1 && path[i+1] != '/'){S.push(dot);}
          else if (dot != "."){S.push(dot);}
        }
        else {
          if (prev[prev.size() - 1] != '/'){
            S.pop();
            S.push(prev + string(1, path[i]));}
          else {
            S.push(string(1, path[i]));
          }
        }
      }
      else {
        S.push(string(1, path[i]));
      }
      i++;
    }
    path.clear();
    while (!S.empty()){
      path = S.top() + path;
      S.pop();
    }
   
    if (path.size() > 0&& path != "/" && path[path.size() - 1] == '/'){path.pop_back();}
    else if (path.size() == 0){path = "/";}
    return path;
  }
};

int main()
{ 
  
  Solution* sol;
  string path = "/..dome../d";
  cout << sol -> simplifyPath(path)<< endl;
  cout << sol -> simplifyPath("/.dome")<< endl;

  path = "/..";
  cout << sol -> simplifyPath(path)<< endl;

  path = "/../";
  cout << sol -> simplifyPath(path)<< endl;

  path = "/home//foo/";
  cout << sol -> simplifyPath(path)<< endl;
  return 0;
}