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

class Solution2 {
public:
  string reorganizeString(string s) {
    /*
    unordered_map<char, int> hashTable;
    for (auto ele : s){
      if (hashTable.find(ele) == hashTable.end()){hashTable[ele] = 1;}
      else {hashTable[ele]++;
        if (hashTable[ele] > (int) s.size() / 2 + 1) {return "";}}
    } */
    for (int i=0; i < s.size() - 1; i++){
      if (s[i] == s[i+1]){
        int idxSwap(i); bool found=false;
        /*
        while (idxSwap >= 0 && s[idxSwap] == s[i]){
          idxSwap--;
          if (s[idxSwap] != s[i]){
            swap(s[idxSwap], s[i-1]);
            found = true;
            break;
          }
        }*/
        if (!found){
          idxSwap = i+1;
          while (idxSwap < s.size() && s[idxSwap] == s[i]){
            idxSwap++;
            if (s[idxSwap] != s[i]){
              swap(s[idxSwap], s[i+1]);
              found = true;
              break;
            }
          }
        }
        if (!found){return "";}
      }
      }
    
    return s;
  }
};


class Solution {
public:
  string reorganizeString(string s) {
    /*
    unordered_map<char, int> hashTable;
    for (auto ele : s){
      if (hashTable.find(ele) == hashTable.end()){hashTable[ele] = 1;}
      else {hashTable[ele]++;
        if (hashTable[ele] > (int) s.size() / 2 + 1) {return "";}}
    } */
    for (int i=0; i < s.size() - 1; i++){
      if (s[i] == s[i+1]){
        int idxSwap(i+1); bool found=false;
        while (idxSwap < s.size() && s[idxSwap] == s[i]){
          idxSwap++;
          if (idxSwap < s.size() && s[idxSwap] != s[i]){
            swap(s[idxSwap], s[i+1]);
            found = true;
            break;
          }
        }
        if (!found){
          idxSwap = i;
          while (idxSwap >= 0 && s[idxSwap] == s[i]){
            idxSwap--;
            cout << idxSwap << ", "<<i << endl;
            if (idxSwap >= 0 && s[idxSwap] != s[i]){
              swap(s[idxSwap], s[i]);
              
              found = true;
              break;
            }
            
          }
          cout << s << endl;
        }
        if (!found){return "";}
      }
      }
    return s;
  }
};

int main()
{ 
  
  Solution* sol;
  //cout << sol -> reorganizeString("aab") << endl;
  //cout << sol -> reorganizeString("aaab") << endl;
  //cout << sol -> reorganizeString("abcaad") << endl;
  //cout << sol -> reorganizeString("aaabcd") << endl;
  cout << sol -> reorganizeString("bcdaaa") << endl;
  return 0;
}