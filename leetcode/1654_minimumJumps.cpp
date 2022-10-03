#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <unordered_set>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;
void print(set<int> x){
  for (auto it= x.begin(); it != x.end(); it++){
    cout << *it <<", ";
    }cout  << endl;
 
}
void print(vector<int> x){
  for (auto it= x.begin(); it != x.end(); it++){
    cout << *it <<", ";}
 
}
class Solution {
public:
  int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> forb(forbidden.begin(), forbidden.end());
    set<int> memo;
    helper(forb, a, b, x, 0, 0, memo);
    print(memo); 
    if (memo.empty()){return -1;}
    else {return *memo.begin();}
  
  }
private:
  void helper(unordered_set<int>  forbidden, int a, int b, int x, int start, int count, set<int>& memo){
    if (start > x){return;}
    if (start == x){memo.insert(count); return;}
    if (forbidden.find(start + a) == forbidden.end()){
      helper(forbidden, a, b, x, start + a, count + 1, memo);
    }
    if (forbidden.find(start - b) == forbidden.end() && start - b >=0){
      helper(forbidden, a, b, x, start - b, count + 1, memo);
    }
  }
};
int main()
{ 
  
  Solution* sol;
  vector<int> forbidden = {14,4,18,1,15};
  cout << sol -> minimumJumps(forbidden, 3, 15, 9)<< endl;

  forbidden = {8,3,16,6,12,20};
  cout << sol -> minimumJumps(forbidden, 15, 13, 11)<< endl;

  forbidden = {1,6,2,14,5,17,4};
  cout << sol -> minimumJumps(forbidden, 16, 9, 7)<< endl;
  
  return 0;
}