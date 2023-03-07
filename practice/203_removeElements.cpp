/*
203. Remove Linked List Elements
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    while (head){
      ListNode* next = head -> next;
      if (head -> val != val){
        cur -> next = head;
        cur = cur -> next;
        cur -> next = nullptr;
      }
      head = next;
    }
    return dummy -> next;
  }
};
