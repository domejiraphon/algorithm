#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
template <typename T>
void print(vector<T> x){
  for (auto elem: x) {
    cout << elem <<", ";
  }
  cout << endl;
}

class Solution {
public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    vector<string> res;
    map<string, int> countDomain;
    for (auto website: cpdomains){helper(countDomain, website);}
    for (auto it = countDomain.begin(); it != countDomain.end(); it++){
      res.push_back(to_string(it -> second) +" "+ it -> first);
    } 
    return res;
  }

private:
  void helper(map<string, int>& countDomain, string word){
    string domain=word.substr(word.find(' ')+1, word.size());
    vector<string> splitDomain; string tmp;
    for (int i=0; i != domain.size(); i++){
      if (domain[i] == '.'){
        splitDomain.push_back(tmp); tmp.clear(); continue;}
      else{
        tmp += domain[i];
      }
    }
    splitDomain.push_back(tmp);
    int rep = stoi(word.substr(0, word.find(' ')));

    tmp= splitDomain[splitDomain.size()-1];
    if (countDomain.find(tmp) == countDomain.end()){countDomain[tmp] = rep;}
    else {countDomain[tmp] += rep;}
    for (int i=splitDomain.size()-2; i != -1; i--){
      tmp = splitDomain[i] + "." + tmp;
      if (countDomain.find(tmp) == countDomain.end()){countDomain[tmp] = rep;}
      else {countDomain[tmp] += rep;}
    }
  }
};

int main()
{
  vector<string> cpdomains={"900 google.mail.com", 
                      "50 yahoo.com", 
                      "1 intel.mail.com",
                      "5 wiki.org"};
  Solution sol;
  vector<string> out;
  out = sol.subdomainVisits(cpdomains);
  print(out);

  return 0;
}