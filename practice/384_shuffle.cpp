#include <iostream>
#include <iterator>
#include <unordered_set>
#include <list>
#include <vector>
using namespace std;
void print(vector<int> x){
  for (auto ele: x){
    cout << ele << ", ";
  }
  cout << endl;
}
class Solution {
  vector<int> cur;
  vector<int> first;
  size_t n;
public:
  Solution(vector<int>& nums) {
    first = nums, cur = nums;
    n = nums.size();
  }
  
  vector<int> reset() {
    cur = first;
    return cur;
  }
  
  vector<int> shuffle() {
    unordered_set<int> S;
    for (int i=0; i< n; i++){
      int newIdx;
      do {
        newIdx = rand() % n;
      } while (!S.count(newIdx));
      S.insert(newIdx);
      cur[i] = first[newIdx];
    }
    return cur;
  }
};


int main()
{
  vector<int> cur = vector<int> {1, 2, 3, 5, 6};
  Solution* sol = new Solution(cur);
  vector<int> out = sol -> shuffle();
  print(out);
  return 0;
}