/*
1721. Swapping Nodes in a Linked List
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
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
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode* front = nullptr;
    ListNode* end = nullptr;
    ListNode* cur = head;
    int i=0;
    while (cur){
      i++;
      if (end)
        end = end -> next;
      if (i == k){
        front = cur;
        end = head;
      }
      
      cur = cur -> next;
    }
    swap(front -> val, end -> val);
    return head;
  }
};
