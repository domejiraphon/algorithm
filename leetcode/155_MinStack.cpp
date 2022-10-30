#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

class MinStack2 {
private:
  stack<pair<int, int>> S;
  int minVal = INT_MAX;
public:
  MinStack() {
  
  }
  
  void push(int val) {
    int minVal = (S.empty()) ? INT_MAX : S.top().second;
    minVal = min(minVal, val);
    S.push({val, minVal});
  }
  
  void pop() {
    S.pop();
  }
  
  int top() {
    return S.top().first;
  }
  
  int getMin() {
    return S.top().second;
  }
};


class MinStack {
private:
  stack<int> S;
  stack<int> minS;
public:
  MinStack() {
  
  }
  
  void push(int val) {
    S.push(val);
    int minVal = (minS.empty()) ? INT_MAX : minS.top();
    if (val <= minVal){
      minS.push(val);
    }
  }
  
  void pop() {
    int topVal = S.top();
    if (topVal == minS.top()){
      minS.pop();
    }
    S.pop();
  }
  
  int top() {
    return S.top();
  }
  
  int getMin() {
    return minS.top();
  }
};

int main()
{ 
  MinStack* obj = new MinStack();
  obj->push(6);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  return 0;
}