#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int countVowelStrings(int n) {
    map<pair<int, int>, int> memo;
    return helper(n, 0, memo);
  }
private:
  int helper(int n, int startIdx, map<pair<int, int>, int>& memo){
    if (n == 0){return 1;}
    if (memo.find({n, startIdx}) != memo.end()){
      return memo[{n, startIdx}];
    }
    int result(0);
    for (int i=startIdx; i < 5; i++){
      result += helper(n - 1, i, memo);
    }
    memo[{n, startIdx}] = result;
    return result;
  }
  
};

int main()
{ 
  Solution* sol;
  
  cout << sol -> countVowelStrings(1) << endl;
  cout << sol -> countVowelStrings(2) << endl;
  cout << sol -> countVowelStrings(33) << endl;
  cout << sol -> countVowelStrings(50) << endl;


  return 0;
}