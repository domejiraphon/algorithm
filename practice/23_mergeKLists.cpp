/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
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
class Compare {
public:
  bool operator() (ListNode* a, ListNode* b){
    return a -> val > b -> val;
  }
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> cur=lists;
    int n=lists.size();
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    
    for (int i=0; i<n; i++){
      ListNode* cur = lists[i];
      if (cur)
        minHeap.push(cur);
    }
    ListNode* head = new ListNode(0);
    ListNode* temp = head;
    while (!minHeap.empty()){
      temp -> next = minHeap.top();
      minHeap.pop();
      if (temp -> next){
        if (temp -> next -> next)
          minHeap.push(temp -> next -> next);
      }
      temp = temp -> next;
    }
    return head -> next;
  }
};
