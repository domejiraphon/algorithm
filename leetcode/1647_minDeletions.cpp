#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(unordered_map<string, int> hashTable){
  for (auto it=hashTable.begin(); it != hashTable.end(); it++){
    cout << it -> first << ", "<< it -> second<< endl;
  }
  cout << endl;
}

void print(unordered_set<int> Set){
  for (auto it : Set){
    cout << it << ", ";
  }
  cout << endl;
}

class Solution {
public:
  int minDeletions(string s) {
    unordered_map<char, int> hashTable;
    unordered_set<int> Set;
    for (auto ele : s){
      if (hashTable.find(ele) == hashTable.end()){hashTable[ele] = 1;}
      else {hashTable[ele]++;}
    }
    int count(0);
    for (auto it=hashTable.begin(); it != hashTable.end(); it++){
      if (Set.find(it -> second) == Set.end()){
        Set.insert(it -> second);
      }
      else{
        int cur= it -> second;
        while (Set.find(cur) != Set.end() && cur > 0){
          cur--;
          count++;
        }
        Set.insert(cur);
      }
    }
    return count;
  }
};

int main()
{ 
  
  Solution* sol;
  cout << sol -> minDeletions("aab") << endl;
  cout << sol -> minDeletions("aaabbbcc") << endl;
  cout << sol -> minDeletions("ceabaacb") << endl;
  return 0;
}