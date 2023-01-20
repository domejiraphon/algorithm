/*
Given the head of a linked list, rotate the list to the right by k places.
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head)
      return head;
    if (k == 0)
      return head;
    int n=0;
    ListNode* cur = head;
    ListNode* temp=nullptr;
    ListNode* last;
    while (cur){
      if (n == k)
        temp = head;
      else if (n > k)
        temp = temp -> next;
      last = cur;
      cur = cur -> next;
      n++;
    }
    if (!temp)
      return rotateRight(head, k % n);
    ListNode* newHead = temp -> next;
    temp -> next = nullptr;
    
    last -> next = head;
    return newHead;
  }
};