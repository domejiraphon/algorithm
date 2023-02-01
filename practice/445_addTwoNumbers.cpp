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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    int carry(0);
    ListNode* head = new ListNode(0);
    ListNode* current = head;
    while (l1 || l2){
      int cur(0);
      cur = (l1) ? cur + (l1 -> val) : cur;
      cur = (l2) ? cur + (l2 -> val) : cur;
      cur += carry;
      carry = cur / 10;
      current -> next = new ListNode(cur % 10);
      current = current -> next;
      l1 = l1 ? l1 -> next : nullptr;
      l2 = l2 ? l2 -> next : nullptr;
    }
    if(carry)
    {
        current -> next = new ListNode(carry);
        
    }
    head = reverseList(head -> next);
    return head;
  }
private:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur){
      ListNode* nextTmp = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = nextTmp;
    }
    return prev;
  }
};
