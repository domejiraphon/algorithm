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
  bool hasCycle(ListNode *head) {
    map <int, bool> check;
    while (head) {
      if (check.find(head -> val) == check.end()) {
        check[head -> val] = true;
        head = head -> next ? head -> next : nullptr;
      }
      else {
        return true;
      }
    }
    return false;
  }
};

int main()
{ 
  ListNode* elem1 = new ListNode(3);
  ListNode* elem2 = new ListNode(2); 
  ListNode* elem3 = new ListNode(0);
  ListNode* elem4 = new ListNode(-4);
  elem1 -> next = elem2; elem2 -> next = elem3;
  elem3 -> next = elem4; elem4 -> next = elem2;
  Solution sol;
  
  ListNode* elem5 = new ListNode(1);
  cout<< sol.hasCycle(elem1) << endl;
  cout<< sol.hasCycle(elem5) << endl;
  return 0;
}