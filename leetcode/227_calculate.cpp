#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>
#include <cmath>
#include <unordered_map>

using namespace std;
void print(stack<int> S){
  while (!S.empty()){
    cout << S.top() << endl;
    S.pop();
  }
}
void print(stack<string> S){
  while (!S.empty()){
    cout << S.top() << endl;
    S.pop();
  }
}

class Solution2 {
public:
  int calculate(string s) {
    int i(0), n(s.size());
    stack<string> S;
    unordered_map<char, function<int (int, int) >> map = {
            { '+' , [] (int a, int b) { return a + b; } },
            { '-' , [] (int a, int b) { return a - b; } },
            { '*' , [] (int a, int b) { return a * b; } },
            { '/' , [] (int a, int b) { return a / b; } }
    };
    while (i < n){
      if (s[i] == ' '){i++;continue;}
      if (isdigit(s[i])){
        int cur = getNumber(s, i);
        S.push(to_string(cur));
      }
      else if (s[i] == '*' || s[i] == '/'){
        int first = stoi(S.top());
        S.pop();
        int oper = i;
        int second = getNumber(s, ++i);
        
        S.push(to_string((int) map[s[oper]](first, second)));
      }
      else {
        S.push(string(1, s[i]));
      }
      i++;
    }
    int eval(0);
    print(S);
    while (S.size() > 1){
      int second = stoi(S.top());
      S.pop();
      string oper = S.top();
      S.pop();
      int first = stoi(S.top());
      S.pop();
      if (!S.empty()){
        int sign = (S.top() == "+") ? 1 : -1;
        S.push(to_string(map[oper[0]](sign * first, second)));
        }
      S.push(to_string(map[oper[0]](first, second)));
    }
  
    return stoi(S.top());
  }
private:
  int getNumber(string s, int& i){
    int cur(0);
    while (s[i] == ' '){
      i++;
    }

    while (isdigit(s[i])){
      cur *= 10;
      cur += (int) (s[i++] - '0');
    }
    i--;
    return cur;
  }
};


class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                cout << operation << endl;
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};
int main()
{ 
  
  Solution* sol;
  string s;
  s = "1-1+1";
  //cout << sol -> calculate(s)<< endl;
  
  s = " 3/2 ";
  //cout << sol -> calculate(s)<< endl;
  s = " 3+5 / 2 ";
  cout << sol -> calculate(s)<< endl;

  s = " 3+ 43 / 2 ";
  //cout << sol -> calculate(s)<< endl;
  return 0;
}