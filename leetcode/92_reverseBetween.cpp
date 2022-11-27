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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* first = new ListNode(1000);
    ListNode * newHead = first;
    int i=1;
    while (i != left){
      first -> next = head;
      first = first -> next;
      head = head -> next;
      i++;
    }
    
    ListNode* secondLast = head;
    ListNode* second = nullptr;
    while( i <= right){
      ListNode* tmp = head -> next;
      head -> next = second;
      second = head;
      head = tmp;
      i++;
    }
    first -> next = second;
    secondLast -> next = head;
    return newHead -> next;
    
  }
};
