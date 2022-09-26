#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> x){
  for (auto vec: x){
  cout << vec << ", ";
  
  }
  cout << endl;
}
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int n = s.size();
    int m = t.size();
    if (n != m) {return false;}

    unordered_map<char, char> hash;
    unordered_set<char> Set;

    for (int i = 0; i < n; i++){
      if (hash.find(s[i]) == hash.end()){
        if (Set.find(t[i]) == Set.end()){
          hash[s[i]] = t[i];
          Set.insert(t[i]);
        }
        else {return false;}
      }
      else {
        if (hash[s[i]] != t[i]){return false;}
      }
      //s.replace(i, 1, string(1, s[i]));
    }
    return true;
  }
};

int main()
{ 
  Solution* sol;
  
  cout << sol -> isIsomorphic("addf", "eggg")<< endl;
  cout << sol -> isIsomorphic("foo", "bar")<< endl;
  cout << sol -> isIsomorphic("paper", "title")<< endl;
  
  return 0;
}