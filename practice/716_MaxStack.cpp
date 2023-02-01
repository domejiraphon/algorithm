/*
716. Max Stack
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.


*/
class MaxStack {
  set<pair<int, int>> stk;
  set<pair<int, int>> sorted;
  int count;
public:
  MaxStack() {
    count=0;
  }
  
  void push(int x) {
    stk.insert({count, x});
    sorted.insert({x, count++});
  }
  
  int pop() {
    pair<int, int> cur = *stk.rbegin();
    stk.erase(cur);
    sorted.erase({cur.second, cur.first});
    return cur.second;
  }
  
  int top() {
    return stk.rbegin() -> second;
  }
  
  int peekMax() {
    return sorted.rbegin() -> first;
  }
  
  int popMax() {
    pair<int, int> cur = *sorted.rbegin();
    sorted.erase(cur);
    stk.erase({cur.second, cur.first});
    return cur.first;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
