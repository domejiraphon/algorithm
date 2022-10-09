#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>

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
    cout << x -> val <<", ";
    x = x -> next;
  }
}

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int out1 = extract(l1);
    int out2 = extract(l2);
    out1 += out2;
    ListNode* out = new ListNode();
    ListNode* cur = out;
    while (out1 > 0){
      cur -> next = new ListNode(out1 % 10);
      cur = cur-> next;
      out1 = out1 / 10;
    }
    return out -> next;
  }
private:
  int extract(ListNode* head){
    int out(0);
    int digit(0);
    while (head){
      out = pow(10, digit) * head -> val + out;
      head = head -> next;
      digit++;
    }
    return out;
  }
};


int main()
{
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(4);
  ListNode* node3 = new ListNode(3);

  node1 -> next = node2; node2 -> next = node3;

  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(4);

  node4 -> next = node5; node5 -> next = node6;
  Solution* sol;
  ListNode* out;
  
  out = sol -> addTwoNumbers(node1, node4);
  print(out);
}
