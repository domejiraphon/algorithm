#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
/*
https://leetcode.com/problems/swap-nodes-in-pairs/
*/
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode* x){
  if (!x)
    {cout << endl; return;}
  cout << x -> val <<", ";
  x = x-> next ? x -> next : nullptr;
  print(x);
}

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* out;
    if (!head)
      return nullptr;
    else if(! head -> next){
      return head;
    }
    tie(out, head) = swap(head);
  
    out -> next -> next = swapPairs(head);
   

    return out;
  }
  tuple<ListNode*, ListNode*> swap(ListNode*prev_node){
    ListNode* cur_node = prev_node;
    ListNode* next_node = prev_node -> next ? prev_node -> next : nullptr;
    ListNode* next_it = next_node -> next ? next_node -> next : nullptr;
    if (!next_node){
      return {prev_node, nullptr};
    }
    //cur_node -> next = next_node -> next;
    cur_node -> next = nullptr;
    next_node -> next = cur_node;
    
    return {next_node, next_it};
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
  

  Solution sol;
  ListNode* out = sol.swapPairs(node1);
  print(out);
  return 0;
}