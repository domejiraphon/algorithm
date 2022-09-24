#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* x){
  while(x){
    cout << x -> val<<", ";
    x = x -> next ? x -> next : nullptr;
  }
}


class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head){return nullptr;}
    vector<int> ele = getElement(head);
    k = k % ele.size();
    for (int i=0; i< k; i++){
      ele.insert(ele.begin(), ele[ele.size() - 1]);
      ele.erase(ele.begin() + ele.size() - 1);
    }
    
    ListNode* out = new ListNode(ele[0]);
    ListNode* cur = out;
    for (int i=1; i< ele.size(); i++){
      cur -> next = new ListNode(ele[i]);
      cur = cur -> next;
    }
    return out;
  }
private:
  vector<int> getElement(ListNode* head){
    vector<int> out;
    while (head){
      out.push_back(head -> val);
      head = (head -> next) ? (head -> next): nullptr;
    }
    return out;
  }
};

int main()
{
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);

  node1 -> next = node2; node2 -> next = node3;
  node3 -> next = node4; node4 -> next = node5;
  Solution* sol;
  
  ListNode* out = sol -> rotateRight(node1, 2);
  print(out);
  return 0;
}