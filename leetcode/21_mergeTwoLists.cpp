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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* out = new ListNode();
    ListNode* cur = out;
    while (list1 || list2) {
      bool found_x=false;
      bool found_y=false;
      int x, y;
      if (list1) {
        x = list1 -> val;
        found_x = true;
      }

      if (list2) {
        y = list2 -> val;
        found_y = true;
      }
      if (found_x && found_y) {
        if (x < y) {
          cur -> next = new ListNode(x);
          cur = cur -> next;
          list1 = list1 ? list1 -> next : nullptr;
        }
        else {
          cur -> next = new ListNode(y);
          cur = cur -> next;
          list2 = list2 ? list2 -> next : nullptr;
        }
      }
      else if (found_x) {
        cur -> next = new ListNode(x);
        cur = cur -> next;
        list1 = list1 ? list1 -> next : nullptr;
      }

      else if (found_y) {
        cur -> next = new ListNode(y);
        cur = cur -> next;
        list2 = list2 ? list2 -> next : nullptr;
      }
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
  ListNode l1_3 = {5};
  ListNode l1_2 = {4, &l1_3};
  ListNode l1_1 = {1, &l1_2};
  ListNode* l1_ptr = &l1_1;

  ListNode l2_4 = {6};
  ListNode l2_3 = {5, &l2_4};
  ListNode l2_2 = {4, &l2_3};
  ListNode l2_1 = {2, &l2_2};
  ListNode* l2_ptr = &l2_1;

  Solution sol;
  ListNode* out;
  out = sol.mergeTwoLists(l1_ptr, l2_ptr);
  sol.visualize(out);
  return 0;
}