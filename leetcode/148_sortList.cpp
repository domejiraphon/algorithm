#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
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

bool sortby(pair<ListNode*, int>& a, pair<ListNode*, int>& b){
  return a.second < b.second;
}
class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head){return nullptr;}
    ListNode* cur = head;
    vector<pair<ListNode*, int>> vect;
    while(cur){
      vect.push_back({cur, cur->val});
      cur = cur -> next;
    }
    sort(vect.begin(), vect.end(), sortby);
    
    head = vect[0].first;
    cur = head;
    for (int i=1; i < vect.size(); i++){
      cur -> next = vect[i].first;
      cur = cur -> next;
    }
    cur -> next = nullptr;
    return head;
  }
};

int main()
{
  Solution* sol;
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(1);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(4);
  node1 -> next = node2; node2-> next = node3;
  node3 -> next = node4; node4 -> next = node5;
  node5 -> next = node6; 
  ListNode* out;
  out = sol -> sortList(node1);
  print(out);
  ListNode* node7 = new ListNode(4);
  out = sol -> sortList(node7);
  print(out);
}
