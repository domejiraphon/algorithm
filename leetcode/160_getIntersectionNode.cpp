/*
160. Intersection of Two Linked Lists

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:
*/
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