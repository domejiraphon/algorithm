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
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    unordered_map<int, int> freq;
  
    ListNode* tmp = head;
    while(tmp){
      freq[tmp -> val]++;
      tmp = tmp -> next;
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* newHead = dummy;
    while(head){
      if (freq[head -> val] == 1){
        dummy -> next = head;
        dummy = dummy -> next;
      }
      else {
        dummy -> next = head -> next;
      }
      head = head -> next;
    }
    return newHead -> next;
  }
};
