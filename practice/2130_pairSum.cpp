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
  int pairSum(ListNode* head) {
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
    int res(0);
    while (prev){
      res = max(res, prev -> val + head -> val);
      prev = prev -> next;
      head = head -> next;
    }
    return res;
    
  }
};

class Solution2 {
public:
  int pairSum(ListNode* head) {
    vector<int> arr;
    while (head){
      arr.push_back(head -> val);
      head = head -> next;
    }
    int res(0);
    int left(0), right(arr.size() - 1);
    while (left < right){
      res = max(res, arr[left++] + arr[right--]);
    }
    return res;
  }
};
