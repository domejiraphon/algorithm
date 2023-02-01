/*
82. Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return head;
    ListNode* dummy = new ListNode(INT_MAX);
    ListNode* left = head;
    if (!head -> next)
      return head;
    ListNode* cur = dummy;
    ListNode* right = head -> next;
    while (right){
      if (left -> val == right -> val){
        while(right && left -> val == right -> val){
          right = right -> next;
        }
        cur -> next = right;
        
      }
      else {
        cur -> next = left;
        cur = cur -> next;
        
      }
      left = right;
        if (right)
          right = right -> next;
    }
    return dummy -> next;
  }
};