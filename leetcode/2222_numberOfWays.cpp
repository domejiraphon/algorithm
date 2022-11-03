#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;


class Solution {
public:
  long long numberOfWays(string s) {
    
    unordered_map<int, int> hash;
    int count = backtrack(s, 0, "", hash);
    return count;
  }
private:
  int backtrack(string& s, int idx, string cur,
      unordered_map<int, int>& hash){
    //if (hash.count(idx)){return hash[idx];}
    if (cur == "11"|| cur == "00"){return 0;}
    if (cur == "101" || cur == "010"){
      return 1;}
    if (idx == s.size() || cur.size() > 3){return 0;}
    int count(0);
    for (int i=idx; i < s.size(); i++){
      cur += s[i];
      count += backtrack(s, i + 1, cur, hash);
      cur.pop_back();
    }
    cout << idx <<": "<< count << endl;
    hash[idx] = count;
    return count;
  }
};

int main()
{ 
  
  Solution* sol;

  cout << sol -> numberOfWays("001101")<< endl;
  return 0;
}