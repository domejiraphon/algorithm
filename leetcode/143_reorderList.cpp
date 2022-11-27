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
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast -> next){
      slow = slow -> next;
      fast = fast -> next -> next;
    }
    ListNode* prev = nullptr;
    while (slow){
      ListNode* tmp = slow -> next;
      slow -> next = prev;
      prev = slow;
      slow = tmp;
    }
    ListNode* first = head; ListNode* second = prev;
    while(second -> next){
      ListNode* tmp = first -> next;
      first -> next = second;
      first = tmp;
      
      tmp = second -> next;
      second -> next = first;
      second = tmp;
    }
  }
};
