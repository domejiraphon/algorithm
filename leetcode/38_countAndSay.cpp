#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  string countAndSay(int n) {
    n--;
    if (n == 0){return "1";}
    vector<string> memo;
    memo.push_back("1");
    for (int i=1; i <= n; i++){
      memo.push_back(count(memo[i - 1]));
    }
    return memo[n];
  }
private:
  string count(string input){
    string out;
    input += "a";
    int n = input.size();
    vector<char> same={input[0]};
    for (int i=1; i < n; i++){
      if (same[0] != input[i]){
        out += to_string(same.size()) + string(1, same[0]);
        same.clear();
      }
      same.push_back(input[i]);
    }
    return out;
  }
};

int main()
{
  Solution* sol;
  //cout << sol -> countAndSay(1)<< endl;
  cout << sol -> countAndSay(2)<< endl;
  cout << sol -> countAndSay(3)<< endl;
  cout << sol -> countAndSay(4)<< endl;
  cout << sol -> countAndSay(5)<< endl;


  return 0;
}