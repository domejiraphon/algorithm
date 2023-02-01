#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <tuple>

using namespace std;
class Node {
public:
  int val;
  Node* next;
  Node* random;
  
  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
void print(Node* head){
  while(head){
    cout << head -> val <<", ";
    head = head -> next;
  }
  cout << endl;
}
void printR(Node* head){
  while(head){
    cout << head -> val <<", ";
    head = head -> random;
  }
  cout << endl;
}

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head){return nullptr;}
    Node* copyNode = new Node(0);
    Node* cur = copyNode;
    unordered_map<Node*, Node*> hash;
    Node* tmp = head;
    while(head){
      cur -> next = new Node(head -> val);
      cur = cur -> next;
      hash[head] = cur;
      head = head -> next ? head -> next : nullptr;
    }
    cur = copyNode -> next;
    while(tmp){
      cur -> random = hash[tmp -> random];
      cur = cur -> next;
      tmp = tmp -> next;
    }
    return copyNode -> next;
  }
};

int main()
{ 
  
  Solution* sol;
  Node* node1 = new Node(7);
  Node* node2 = new Node(13);
  Node* node3 = new Node(11);
  Node* node4 = new Node(10);
  Node* node5 = new Node(1);
  node1 -> next = node2; node2 -> next = node3;
  node3 -> next = node4; node4 -> next = node5;

  Node* out;
  out = sol -> copyRandomList(node1);
  
  return 0;
}