#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();
    unordered_map<char, char> hashTable;
    for (int i=0; i < n - 1; i++){
      if (s[i] != s[i + 1]){
        hashTable[s[i+1]] = s[i];
      }
    }
  }
private:
  int countLongest(string s, int k, unordered_map<char, char> hashTable){
    vector<int> memo(s.size());
    for (auto ele: s){
      if (hashTable.find(ele) != hashTable.end()){

      }
    }
  }
};
int main()
{ 
  Solution* sol;
  cout << sol -> characterReplacement("ABAB", 2) << endl;
  cout << sol -> characterReplacement("AABABBA", 1) << endl;


  return 0;
}