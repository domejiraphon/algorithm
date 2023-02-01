/*
148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
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
bool compare(ListNode* a, ListNode* b){
  return a -> val < b -> val;
}

class Solution2 {
public:
  ListNode* sortList(ListNode* head) {
    if (!head){return head;}
    vector<ListNode*> flatten;
    while (head){flatten.push_back(head); head = head -> next;}
    sort(flatten.begin(), flatten.end(), compare);
    int n =flatten.size();
    
    head = flatten[0];
    ListNode* cur=head;
    
    for (int i=1; i<n; i++){
      cur -> next = flatten[i];
      cur = cur -> next;
    }
    cur -> next = nullptr;
    return head;
  }
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head -> next){return head;}
    ListNode* right = getMid(head);
    ListNode* sortLeft = sortList(head);
    ListNode* sortRight = sortList(right);
    return merge(sortLeft, sortRight);
  }

private:
  ListNode* merge(ListNode* left, ListNode* right){
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (left && right){
      if (left -> val < right -> val){
        cur -> next =left;
        left = left -> next;
      }
      else {
        cur -> next = right;
        right = right -> next;
      }
      cur = cur -> next;
    }
    if (left){cur -> next = left;}
    if (right){cur -> next = right;}
    return dummy -> next;
  }
  
  
  ListNode* getMid(ListNode* head) {
    ListNode* midPrev = nullptr;
    while (head && head->next) {
      midPrev = (midPrev == nullptr) ? head : midPrev->next;
      head = head->next->next;
    }
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
  }
};