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
    unordered_map<string, int> countPaired;
    for (auto domain: cpdomains)
      split(countPaired, domain);
    vector<string> res;
    for (auto it:countPaired){
      res.push_back(to_string(it.second) + " " + it.first);
    }
    return res;
  }
private:
  void split(unordered_map<string, int>& num, string& domain){
    int n=domain.size();
    string cur = "";
    int rep=0;
    for (int i=0; isdigit(domain[i]); i++){
      rep = 10 * rep + (domain[i] - '0');
    }
    for (int i=n-1; domain[i] != ' '; i--){
      if (domain[i] == '.'){
        num[cur] += rep;
      }
      cur = domain[i] + cur;
    }
    num[cur] += rep;
  }
};