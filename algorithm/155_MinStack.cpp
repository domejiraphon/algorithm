/*
155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.


*/
class MinStack {
  stack<pair<int, int>> stk;
  int minVal;
public:
  MinStack() {
      
  }
  
  void push(int val) {
    if (stk.empty())
      stk.push({val, val});
    else {
      int curMin = min(val, stk.top().second);
      stk.push({val, curMin});
    }
  }
  
  void pop() {
    if (!stk.empty())
      stk.pop();
  }
  
  int top() {
    return stk.top().first;
  }
  
  int getMin() {
    return stk.top().second;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */