/*
1381. Design a Stack With Increment Operation
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
*/
struct Node {
  int val;
  Node* next=nullptr;
  Node* prev = nullptr;
  Node(int v){
    val = v;
  }
};

class CustomStack {
  int capacity;
  int size;
  Node* bottom;
  Node* top;
public:
  CustomStack(int maxSize) {
    capacity = maxSize;
    bottom = top = new Node(0);
    size = 0;
  }
  
  void push(int x) {
    if (size < capacity){
      Node* cur = new Node(x);
      top -> next = cur;
      cur -> prev = top;
      top = cur;
      size++;
    }
  }
  
  int pop() {
    if (size > 0 && top){
      int val = top -> val;
      Node* tmp = top;
      top = top -> prev;
      delete tmp;
      size--;
      return val;
    }
    return -1;
  }
  
  void increment(int k, int val) {
    int i=0;
    Node* cur = bottom -> next;
    k = min(k, size);
    while (i < k && cur){
      cur -> val += val;
      cur = cur -> next;
      i++;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
