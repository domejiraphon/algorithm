#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
void print(vector<vector<string>> strs){
    for (auto row: strs){
      for (auto x: row){
        cout << x<< ", ";
      }
      cout << endl;
    }
  }
void print(vector<string> strs){
   
    for (auto x: strs){
      cout << x<< ", ";
    }
    cout << endl;

  }
void print(unordered_map<string, int> hashTable){
  for (auto it=hashTable.begin(); it != hashTable.end(); it++){
    cout << it -> first << ", "<< it -> second<< endl;
  }
  cout << endl;
}
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> hashTable;
    for (int i=0; i < strs.size(); i++){
      if (hashTable.find(strs[i]) == hashTable.end()){
        hashTable[strs[i]] = 1;
      }
      else{
        hashTable[strs[i]]++;
      }
    }
    
    vector<vector<string>> out;
    for (auto it=hashTable.begin(); it != hashTable.end(); it++){
      vector<string> ana = createAnagrams(it -> first);
      vector<string> cur;
      print(ana); exit(0);
      for (auto ele: ana){
        if (hashTable.find(ele) != hashTable.end()){
          //for (int i=0; i != hashTable[ele]; i++){cur.push_back(ele);}
          cur.push_back(ele);
          hashTable.erase(ele);
        }
      }
      print(hashTable);
      cout << endl;
      if (cur.size() !=0){out.push_back(cur);}
    }
    return out;
  }
  
private:
  vector<string> createAnagrams(string str){
    vector<string> out;
    for (int i=0; i != str.size(); i++){
      string tmp = str;
      string cur = string(1, str[i]);
      tmp = cur + tmp.erase(i, 1);
      out.push_back(tmp);
    }
    return out;
  }
  
};

int main()
{ 
  
  Solution* sol;
  vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
  vector<vector<string>> out;
  out = sol -> groupAnagrams(strs);
  print(out);
  //cout << sol -> validPalindrome("abca")<< endl;
  //cout << sol -> validPalindrome("aba")<< endl;
  return 0;
}