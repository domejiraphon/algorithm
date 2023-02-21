/*
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.
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
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    string out = toString(head);
    int left=0, right = out.size() - 1;
    while (left < right){
      if (out[left++] != out[right--])
        return false;
      
    }
    return true;
  }
private:
  string toString(ListNode* head){
    string out="";
    while (head){
      out += head -> val + '0';
      head = head -> next;
    }
    return out;
  }
};