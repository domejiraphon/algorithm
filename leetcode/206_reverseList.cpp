#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* x){
  while(x){
    cout << x -> val<< ", ";
    x = x -> next ? x -> next : nullptr;
  }
}
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while(cur){
      ListNode* tmp = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
};

int main()
{ 
  
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);

  node1 -> next = node2; node2 -> next = node3;
  node3 -> next = node4; node4 -> next = node5;
  Solution* sol;

  ListNode* out;
  out = sol -> reverseList(node1);
  print(out);
  return 0;
}