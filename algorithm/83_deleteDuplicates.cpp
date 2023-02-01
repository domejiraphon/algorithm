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

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (! head){
      return head;
    }
    if (! head -> next){
      return head;
    }
    ListNode* out = new ListNode();
    ListNode* out2 = out;
   
    out2 -> next = new ListNode(head -> val);
    out2 = out2 -> next;
    int prev_val = head -> val;
    while (head != nullptr) {
      int cur = head -> val;
      if (cur != prev_val){
        out2 -> next = new ListNode(cur);
        out2 = out2 -> next;
        prev_val = cur;
      }
      head = head -> next ? head -> next : nullptr;
    }
    return out -> next;
  }

  void visualize(const ListNode* l1_ptr){
    while (l1_ptr != nullptr){
        cout << l1_ptr -> val << ", ";
        if (l1_ptr -> next)
          l1_ptr = l1_ptr -> next;
        else
          l1_ptr = nullptr;
    }
    cout << endl;
  };
};

int main()
{ 
  ListNode l1_4 = {5};
  ListNode l1_3 = {5, &l1_4};
  ListNode l1_2 = {1, &l1_3};
  ListNode l1_1 = {1, &l1_2};
  ListNode* l1_ptr = &l1_1;

  Solution sol;
  ListNode* out = sol.deleteDuplicates(l1_ptr);
  sol.visualize(out);
  ListNode* l2_ptr;
  ListNode* out2 = sol.deleteDuplicates(l2_ptr);
  sol.visualize(out2);
  return 0;
}