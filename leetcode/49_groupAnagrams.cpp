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

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> hash;
    int n = strs.size();
    for (auto ele: strs){
      string tmp = ele;
      sort(tmp.begin(), tmp.end());
      hash[tmp].push_back(ele);
    }
    vector<vector<string>> out;
    for (auto it=hash.begin(); it != hash.end(); it++){
      out.push_back(it -> second);
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
 
  return 0;
}