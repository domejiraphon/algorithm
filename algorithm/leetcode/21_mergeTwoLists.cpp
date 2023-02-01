/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    ListNode* left=list1;
    ListNode* right=list2;
    while (left || right){
      if (left && right){
        if (left -> val < right -> val){
          cur -> next = left;
          left = left -> next;
        }
        else {
          cur -> next = right;
          right = right -> next;
        }
        
      }
      else {
        if (left){
          cur -> next = left;
          left = left -> next;
        }
        else if (right){
          cur -> next = right;
          right = right -> next;
        }
      }
      cur = cur -> next;
    }
    return dummy -> next;
  }
};