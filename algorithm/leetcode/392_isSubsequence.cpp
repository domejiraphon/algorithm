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
  bool isSubsequence(string s, string t) {
    int idxS(0), idxT(0);
    int n(s.size()), m(t.size());
    while (idxS < n && idxT < m){
      if (s[idxS] == t[idxT]){
        idxS++; idxT++;
      }
      else {
        idxT++;
      }
    }
    return (idxS == n) ? true : false;
  }
};

int main()
{ 
  Solution* sol;
  
  cout << sol -> isSubsequence("abc", "ahbgdc")<< endl;
  cout << sol -> isSubsequence("axc", "ahbgdc")<< endl;
  return 0;
}