/*
24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
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
  ListNode* swapPairs(ListNode* head) {
    if (!head)
      return head;
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    
    ListNode* prev = dummy;
    
    while (head && head -> next){
      ListNode* first = head;
      ListNode* second = head -> next;
      prev -> next = second;
      first -> next = second -> next;
      second -> next = first;
      prev = first;
      head = first -> next;
    }

    return dummy -> next;
  }
};