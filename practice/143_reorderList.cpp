/*
143. Reorder List

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
  void reorderList(ListNode* head) {
    ListNode* slow=head,* fast = head;
    while(fast && fast -> next){
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    ListNode* prev = nullptr;
    ListNode* cur = slow;
    while (cur){
      ListNode* temp = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = temp;
    }
    ListNode* first = head,* second = prev;
    
    while (second -> next){
      ListNode* temp = first -> next;
      first -> next = second;
      first = temp;
      
      temp = second -> next;
      second -> next = first;
      second = temp;
    }
    
  }
};