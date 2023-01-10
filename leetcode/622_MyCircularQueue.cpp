/*
622. Design Circular Queue
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 
*/
struct Node {
  int val;
  Node* next = {};
  Node (int v){
    val = v;
  }
};

class MyCircularQueue {
  int capacity;
  Node* head=nullptr;
  Node* tail = head;
  int count;
public:
  MyCircularQueue(int k) {
    capacity = k;
    count = 0;
  }
  
  bool enQueue(int value) {
    if (count < capacity){
      Node* newNode = new Node(value);
      if (count == 0)
        head = tail = newNode;
      else{
        tail -> next = newNode;
        tail = tail -> next;
      }
      count++;
      return true;
    }
    return false;
  }
  
  bool deQueue() {
    if (count > 0){
      Node* prevHead = head;
      head = head -> next;
      delete prevHead;
      count--;
      return true;
    }
    return false;
  }
  
  int Front() {
    return (head) ? head -> val : -1;
  }
  
  int Rear() {
    return (tail) ? tail -> val : -1;
  }
  
  bool isEmpty() {
    return (count == 0);
  }
  
  bool isFull() {
    return (count == capacity);
  }
};


class MyCircularQueue {
  vector<int> queue;
  int capacity;
  int headIdx;
  int count;
public:
  MyCircularQueue(int k) {
    queue.resize(k, -1);
    capacity = k;
    headIdx = 0;
    count = 0;
  }
  
  bool enQueue(int value) {
    if (count < capacity){
      queue[(headIdx + count) % capacity] = value;
      count++;
      return true;
    }
    else
      return false;
  }
  
  bool deQueue() {
    if (count > 0){
      headIdx = (headIdx + 1) % capacity;
      count--;
      return true;
    }
    else
      return false;
  }
  

  int Front() {
    return (count > 0) ? queue[headIdx] : -1;
  }
  
  int Rear() {
    return (count > 0) ? queue[(headIdx + count - 1) % capacity] : -1;
  }
  
  bool isEmpty() {
    return count == 0;
  }
  
  bool isFull() {
    return count == capacity;
  }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
