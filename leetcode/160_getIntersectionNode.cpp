/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a=headA;
    ListNode *b=headB;
    while (a != b){
      a = !a ? headB : a -> next;
      b = !b ? headA : b -> next;
    }
    return a;
  }
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> list;
    while (headA){
      list.insert(headA);
      headA = headA -> next;
    }
    while (headB){
      if (list.count(headB))
        return headB;
      headB = headB -> next;
    }
    return nullptr;
  }
};