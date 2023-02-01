#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    unordered_map<char, int> hash;
    int n(s.size());
    for (int i=0; i < n; i++){
      hash[s[i]]++;
    }
    for (int i=0; i < n; i++){
      if (hash[s[i]] == 1){return i;}
    }
    return -1;
  }
};
int main()
{ 
  Solution* sol = new Solution();
  
  return 0;
}