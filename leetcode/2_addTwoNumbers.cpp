/* 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry=0;
    ListNode* out = new ListNode(0);
    ListNode* head = out;
   
    while (l1 || l2 || carry != 0){
      int cur = 0;
      if (l1){cur += l1 -> val;}
      if (l2){cur += l2 -> val;}
      cur += carry;
      carry = cur / 10;
      cur = cur % 10;
      head -> next = new ListNode(cur);
      head = head -> next;
      if (l1){
        l1 = l1 -> next ? l1 -> next : nullptr;
      }
      if (l2){
        l2 = l2 -> next ? l2 -> next : nullptr;
      }
    }
    return out -> next;
  }
};