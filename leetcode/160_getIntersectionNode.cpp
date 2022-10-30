#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void print(ListNode* x){
  while (x){
    cout << x -> val << ", ";
    x = x -> next ? x ->next : nullptr;
  }
}
class Solution2 {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA = headA;
    ListNode* curB = headB;
    int lengthA = getLength(curA);
    int lengthB = getLength(curB);
    
    for (int i=0; i<lengthA; i++){
      curB = headB;
      for (int j=0; j<lengthB; j++){
        if (curA == curB){return curA;}
        curB = curB -> next ? curB -> next : nullptr;
      }
      curA = curA -> next ? curA -> next : nullptr;
    }
    return nullptr;
  }
private:
  int getLength(ListNode* head){
    int length(0);
    while (head){
      head = head -> next ? head -> next: nullptr;
      length++;
    }
    return length;
  }
};

class Solution3 {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curB;
    while (headA){
      curB = headB;
      while (curB){
        if (headA == curB){
          return curB;
        }
        curB = curB -> next ? curB -> next : nullptr;
      }
      headA = headA -> next ? headA -> next : nullptr;
    }
    return nullptr;
  }
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curB;
    unordered_set<ListNode*> S;
    while (headA){
      S.insert(headA);
      headA = headA -> next ? headA -> next : nullptr;
    }
    while (headB){
      if (S.find(headB) != S.end()){
        return headB;
      }
      
      headB = headB -> next ? headB -> next : nullptr;
    }
    return nullptr;
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
  Solution* sol;
 
  ListNode* out= sol -> getIntersectionNode(elem1, elem1_1);
  print(out);
  return 0;
}