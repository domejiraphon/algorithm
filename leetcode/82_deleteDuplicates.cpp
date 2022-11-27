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
    ListNode* prev = new ListNode(INT_MAX);
    ListNode* newHead = prev;
    while (head){
      if (head -> next && head -> val == head -> next -> val){
        while (head -> next && head -> val == head -> next -> val){
          head = head -> next;
        }
        prev -> next = head -> next;
      }
      else {
        prev -> next = head;
        prev = prev -> next;
      }
      head = head -> next;
    }
    return newHead -> next;
  }
};
