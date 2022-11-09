#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> counterS(26, 0), counterT(26, 0);
    counter(counterS, s); counter(counterT, t);
    for (int i=0; i < 26; i++){
      if (counterS[i] != counterT[i]){
        return false;
      }
    }
    return true;
  }
private:
  void counter(vector<int>& count, string& s){
    for (auto ele : s){
      count[ele - 'a']++;
    }
  }
};

class Solution {
public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end()); sort(t.begin(), t.end());
    return (s == t) ? true : false;
  }
};

class Solution2 {
public:
  bool isAnagram(string s, string t) {
    map<char, int> hashS, hashT;
    getMap(s, hashS); getMap(t, hashT);
    for (auto it=hashS.begin(); it != hashS.end(); it++){
      if ((!hashT.count(it -> first)) ||
        (hashT.count(it -> first) && hashT[it -> first] != it ->second))
        {
        return false;
      }
    }
    return (hashS.size() == hashT.size()) ? true : false;
  }
private:
  void getMap(string s, map<char, int>& hash){
    for (auto ele: s){
      hash[ele]++;
    }
  }
};


int main()
{ 
  Solution* sol;
  vector<int> nums = {1,0,-1,0,-2,2};
  vector<vector<int>> out;
  out = sol -> fourSum(nums, 0);

  nums = {2,2,2,2,2};
  vector<vector<int>> out;
  out = sol -> fourSum(nums, 8);
  
  return 0;
}