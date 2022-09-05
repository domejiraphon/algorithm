#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    print(headA); print(headB);
    ListNode* reverse_A = reverse(headA);
    ListNode* reverse_B = reverse(headB);
    
    print(reverse_A); 
    print(reverse_B);
    return helper(reverse_A, reverse_B);
  }

  ListNode* helper(ListNode *headA, ListNode *headB) {
    if (headA != headB) {
      return nullptr;
    }
    ListNode* next_headA = headA -> next ? headA -> next : nullptr;
    ListNode* next_headB = headB -> next ? headB -> next : nullptr;
    if (next_headA == next_headB) {
      return helper(next_headA, next_headB);
    }
    else {
      return headA;
    }
  }

  ListNode *reverse(ListNode *head){
    // Initialize current, previous and next pointers
    ListNode* current = head;
    ListNode* prev = NULL, *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
  }
  void print(ListNode* head) {
    while (head) {
    cout << head -> val << ", ";
    head = head -> next ? head -> next : nullptr;
  }
  cout << endl;
  }
};

int main()
{ 
  ListNode* elem1 = new ListNode(4);
  ListNode* elem2 = new ListNode(1); 
  ListNode* elem3 = new ListNode(8);
  ListNode* elem4 = new ListNode(4);
  ListNode* elem5 = new ListNode(5);
  elem1 -> next = elem2; elem2 -> next = elem3;
  elem3 -> next = elem4; elem4 -> next = elem5;

  ListNode* elem1_1 = new ListNode(5);
  ListNode* elem2_1 = new ListNode(6);
  ListNode* elem3_1 = new ListNode(1);
  elem1_1 -> next = elem2_1; elem2_1 -> next = elem3_1;
  elem3_1 -> next = elem3;
  Solution sol;
 
  ListNode* out= sol.getIntersectionNode(elem1, elem1_1);
  
  return 0;
}