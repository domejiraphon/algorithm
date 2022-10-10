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
  cout << endl;
}

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    int carry(0);
    int val;
    while (cur1 && cur2){
      val = carry + cur1 -> val + cur2 -> val;
      carry = (int) val / 10;
      val %= 10;

      cur1 = cur1 -> next; cur2 = cur2 -> next;
      cur -> next = new ListNode(val);
      cur = cur -> next;
    }
    addItself(cur1, cur, carry);
    addItself(cur2, cur, carry);
    if (carry == 1){cur -> next = new ListNode(1);}
    return head -> next;
  }
private:
  void addItself(ListNode* cur1, ListNode*& cur, int& carry){
    if (!cur1){return;}
    int val;
    while (cur1){
      val = carry + cur1 -> val;
      cur1 = cur1 -> next;
      
      carry = (int) val / 10;
      val %= 10;
      
      cur -> next = new ListNode(val);
      cur = cur -> next;
      if (carry == 0){
        cur -> next = cur1; break;
      }
    }
    
  }
};

int main()
{
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(4);
  ListNode* node3 = new ListNode(3);

  node1 -> next = node2; node2 -> next = node3;

  ListNode* node4 = new ListNode(9);
  ListNode* node5 = new ListNode(9);
  ListNode* node6 = new ListNode(1);
  ListNode* node7 = new ListNode(1);
 

  node4 -> next = node5; node5 -> next = node6;
  
  Solution* sol;
  ListNode* out;
  
  out = sol -> addTwoNumbers(node4, node7);
  print(out);
}
