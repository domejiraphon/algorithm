#include <iostream>
#include <iterator>
#include <map>
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

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* out = new ListNode();
    ListNode* out2 = out;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr){
      int sum=0;
      if (l1){
        sum += l1 -> val;
      }
      if (l2){
        sum += l2 -> val;
      }
      sum += carry;
      carry = (int) sum / 10;
      
      out2 -> next = new ListNode(sum % 10);
      out2 = out2 -> next;

      if (l1 -> next){
        l1 = l1 -> next;
      }
      else
        l1 = nullptr;

      if (l2 -> next){
        l2 = l2 -> next;
      }
      else 
        l2 = nullptr;
    
    };
    return out -> next;
  }
  void visualize(const ListNode* l1_ptr){
    while (l1_ptr != nullptr){
        cout << l1_ptr -> val << endl;
        l1_ptr = l1_ptr -> next;
  };
  };
};

int main()
{
  ListNode l1_1 = {3};
  ListNode l1_2 = {4, &l1_1};
  ListNode l1_3 = {2, &l1_2};
  ListNode* l1_ptr = &l1_3;

  ListNode l2_1 = {4};
  ListNode l2_2 = {6, &l2_1};
  ListNode l2_3 = {5, &l2_2};
  ListNode* l2_ptr = &l2_3;
  
  Solution sol;
  ListNode* out;
  out = sol.addTwoNumbers(l1_ptr, l2_ptr);
  sol.visualize(out);
}
