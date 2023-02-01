#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <list>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode* ptr){
  while (ptr){
    cout << ptr -> val <<", ";
    ptr =  ptr -> next;
  }
  cout << endl;
}

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int length =findLength(head);
    length -= n;
    if (length == 0){return head -> next;}
    ListNode* cur = head;
    
    while (length >= 0){
      length--;
      if (length == 0){
        ListNode* nextNode = cur -> next -> next;
        cur -> next = nextNode;
        break;
      }
      
      cur = cur -> next;
    }
    return head;
  }
private:
  int findLength(ListNode* head){
    int count=0;
    while (head){
      count++;
      head = head -> next;
    }
    return count;
  }
};

int main()
{
  Solution* sol;
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);
  node1 -> next = node2; node2-> next = node3;
  node3 -> next = node4; node4 -> next = node5;
  ListNode* out;
  out = sol -> removeNthFromEnd(node1, 5);
  print(out);
  out = sol -> removeNthFromEnd(node5, 1);
  print(out);
}
