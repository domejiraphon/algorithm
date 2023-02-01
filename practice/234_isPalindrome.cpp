#include <iostream>
#include <iterator>
#include <map>
#include <vector>
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

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    string count;
    while(head){
      count += to_string(head -> val);
      head = head -> next;
    }
    int left(0), right(count.size() - 1);
    while (left < right){
      if (count[left] == count[right]){
        left++; right--;
      }
      else {return false;}
    }
    return true;
  }
};
int main()
{
  Solution* sol;
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(2);
  ListNode* node4 = new ListNode(1);
  //ListNode* node5 = new ListNode(5);
  node1 -> next = node2; node2-> next = node3;
  node3 -> next = node4; //node4 -> next = node5;
  ListNode* out;
  cout << sol -> isPalindrome(node1)<< endl;
  cout << sol -> isPalindrome(new ListNode(1))<< endl;
}
