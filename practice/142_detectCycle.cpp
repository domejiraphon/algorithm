#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>
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
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> hash;
    ListNode * cur=head;
    while (cur){
      ListNode* nextNode= cur -> next ? cur -> next : nullptr;
      if (nextNode && hash.find(nextNode) == hash.end()){
        hash.insert(cur);
      }
      else if (nextNode && hash.find(nextNode) != hash.end()){
        return nextNode;
      }
      cur = nextNode;
    }
    return nullptr;
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
  Solution* sol;
  
  ListNode* elem5 = new ListNode(1);
  
  //cout<< sol -> detectCycle(elem1) << endl;
  //cout<< sol -> detectCycle(elem5) << endl;

  ListNode* elem1_1 = new ListNode(1);
  ListNode* elem2_1 = new ListNode(2);
  elem1_1 -> next = elem2_1; elem2_1 -> next =  elem1_1;
  cout<< sol -> detectCycle(elem1_1) << endl;
  cout << "elem1: "<< elem1_1 << endl;
  cout << elem2_1 << endl;
  return 0;
}