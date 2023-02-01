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
template <typename T>
void print(vector<T> x){
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
}
template <typename T>
void print(unordered_set<T> x){
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
}

void print(unordered_map<char, int> x){
  for (auto it=x.begin(); it != x.end(); it++){
    cout << it -> first <<": "<< it -> second << ", ";
  }
  cout << endl;
}

class Solution2 {
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_set<string> res;
    backtracking(res, p, "", p.size());
    int n = s.size();
    int m = p.size();
    vector<int> out;
    for (int i=0; i <= n - m; i++){
      if (res.find(s.substr(i, m)) != res.end()){
        out.push_back(i);
      }
    }
    return out;
  }
private:
  void backtracking(unordered_set<string>& res, string p, string cur, int out){
    if (out == cur.size()){res.insert(cur); return;}
    int n = p.size();
    for (int i=0; i < n; i++){
      if (i > 1 && p[i] == p[i-1]){continue;}
      string tmp=p;
      tmp.erase(tmp.begin() + i);
      backtracking(res, tmp, cur + p[i], out);
    }
  }
};

class Solution{
public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> hashP =  getHash(p);
    int n = s.size();
    int m = p.size();
    unordered_map<char, int> hashS = getHash(s.substr(0, m));
    vector<int> out;
    for (int i=0; i <= n - m; i++){
      bool yes(true);
      
      if (i != 0) {hashS[s[i+m - 1]]++;}
      print(hashS);
      for (auto it=hashS.begin(); it != hashS.end(); it++){
        //cout << it -> first <<": "<< hashP[it -> first] << ", " << it -> second << endl;
        if (hashP[it -> first] != it -> second){
          yes = false;
          break;
        }
      }
      hashS[s[i]]--;
      if (yes){out.push_back(i);}
    }
    return out;
  }
private:
  unordered_map<char, int> getHash(string s){
    unordered_map<char, int> hash;
    int n = s.size();
    for (int i=0; i < n; i++){
      hash[s[i]]++;
    }
    return hash;
  }
};

int main()
{
  Solution* sol;
  vector<int> out;
  /*
  out = sol -> findAnagrams("abcba", "abc");
  print(out);
  
  
  out = sol -> findAnagrams("abab", "ab");
  print(out);*/
  out = sol -> findAnagrams("cbaebabacd", "abc");
  print(out);

  return 0;
}