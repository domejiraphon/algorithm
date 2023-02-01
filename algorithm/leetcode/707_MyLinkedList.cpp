/*
707. Design Linked List
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
*/
struct Node {
  int val;
  Node* next=nullptr;
  Node (int v){
    val = v;
  }
};

class MyLinkedList {
  Node* head;
  int size;
public:
  MyLinkedList() {
    head = nullptr;
    size = 0;
  }
  
  int get(int index) {
    if (index < 0 || index >= size)
      return -1;
    int i=0;
    Node* cur = head;
    while (i < index){
      cur = cur -> next;
      i++;
    }
    return cur -> val;
  }
  
  void addAtHead(int val) {
    addAtIndex(0, val);
  }
  
  void addAtTail(int val) {
    addAtIndex(size, val);
  }
    
  void addAtIndex(int index, int val) {
    if (index > size)
      return;
    if (index < 0)
      index = 0;
    int i=0;
    Node* cur = head;
    Node* newNode = new Node(val);
    if (index == 0){
      newNode -> next = cur;
      head = newNode;
    }
    else {
      while (i < index -1){
        cur = cur -> next;
        i++;
      }
      newNode -> next = cur -> next;
      cur -> next = newNode;
    }

    size++;
  
  }
  
  void deleteAtIndex(int index) {
    if (index < 0 || index >= size)
      return;
    
    int i=0;
    Node* cur = head;
    if (index == 0){
      Node* temp = head -> next;
      delete head;
      head = temp;
    }
    else {
      while (i < index - 1){
        cur = cur -> next;
        i++;
      }
      Node* temp = cur -> next -> next;
      delete cur -> next;
      cur -> next = temp;
    }
  
    size--;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
