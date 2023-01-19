/*
811. Subdomain Visit Count
A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.

A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.

For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.
*/
class Solution {
public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> map;
    for (string domain: cpdomains)
      splitDomains(domain, map);
    vector<string> res;

    for (auto it=map.begin(); it != map.end(); it++){
      string cur = to_string(it -> second) + ' ' + it -> first;
      res.push_back(cur);
    }
    return res;
  }
private:
  void splitDomains(string& domain, unordered_map<string, int>& map){
    int n=domain.size();
    int i=0;
    int num=getNumber(domain, i);
    i=n-1;
    string cur="";
    while (domain[i] != ' '){
      if (domain[i] == '.'){
        map[cur] += num;
      }
      cur = domain[i--] + cur;
    }
    map[cur] += num;
  }
  int getNumber(string& domain, int& i){
    int cur=0;
    while (isdigit(domain[i]))
      cur = 10 * cur +(domain[i++] - '0');
    return cur;
  }
};