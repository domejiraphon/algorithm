#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <cmath>
#include <list>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode* ptr){
  while (ptr){
    cout << ptr -> val <<", ";
    ptr =  ptr -> next;
  }
  cout << endl;
}

class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = head;
    ListNode* even = head -> next;
    ListNode* cur = head -> next;
    while (cur && cur -> next){
      odd -> next = cur -> next;
      odd = odd -> next;
      cur -> next = odd -> next;
      cur = cur -> next;
      
    }
    odd -> next = even;
    return head;
  }
};

int main()
{
  Solution* sol;
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(1);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(4);
  node1 -> next = node2; node2-> next = node3;
  node3 -> next = node4; node4 -> next = node5;
  node5 -> next = node6; 
  ListNode* out;
  out = sol -> oddEvenList(node1);
  print(out);
}
