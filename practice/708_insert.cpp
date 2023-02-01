
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
  Node* insert(Node* head, int insertVal) {
    if (!head){
      Node* out = new Node(insertVal);
      out -> next = out;
      return out;
    }
    Node* prev = head;
    Node* cur = head -> next;
    bool insert(false);
    do {
      if (insertVal >= prev -> val && insertVal <= cur -> val){
        insert = true;
      }
      else if (prev -> val > cur -> val){
        if (insertVal >= prev -> val || insertVal <= cur -> val){
          insert = true;
        }
      }
      if (insert){
        prev -> next = new Node(insertVal, cur);
        return head;
      }
      prev = cur; cur = cur -> next;
    } while (prev != head);
    
    prev -> next = new Node(insertVal, cur);
    return head;
  }
};