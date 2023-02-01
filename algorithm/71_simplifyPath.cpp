/* 71. Simplify Path
Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.
*/
class Solution {
  int n;
public:
  string simplifyPath(string path) {
    
    stack<string> stk;
    int i=0;
    n=path.size();
    while (i < n){
      if (path[i] == '/'){
        if (!stk.empty() && stk.top() == "/"){
          i++;
          continue;
        }
        else{
          if (i != n -1)
            stk.push("/");
        }  
      }
      else if (path[i] == '.'){
        string cur=getNext(path, i);
        if (cur == ".."){
          if (stk.size() != 1)
            stk.pop(); stk.pop();
        }
        else if (cur != ".")
          stk.push(cur);
      }
      else {
        string cur=getNext(path, i);
        stk.push(cur);
      }
      i++;
    }
    string res;
    while (!stk.empty()){
      res = stk.top() + res;
      stk.pop();
    }
    if (res == "")
      return "/";
    else if (res.size() > 1 && res[res.size() - 1] == '/')
      return res.substr(0, res.size() - 1);
    else
      return res;
  }
private:
  string getNext(string& path, int& i){
    string cur="";
    while (i<n && path[i] != '/'){
      cur += path[i++];
    }
    i--;
    return cur;
  }
};