/*
97. Interleaving String
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/
class Solution {
private:
  string S1, S2, S3;
  int n1, n2, n3;
  map<vector<int>, bool> hash;
public:
  bool isInterleave(string s1, string s2, string s3) {
    n1 = s1.size(); n2 = s2.size(); n3 = s3.size();
    if ((n1 + n2) != n3){return false;}
    S1 = s1; S2 = s2; S3 = s3;
    
    return check(0, 0, 0);
  }
private:
  bool check(int i, int j, int k){
    if (i == n1 && j == n2 && k == n3){return true;}
    //if (i >= n1 || j >= n2 || k >= n3){return false;}
    if (hash.count({i, j, k})){
      return hash[vector<int> {i, j, k}];
    }
    bool out=false;
    if (S1[i] == S3[k] && S2[j] != S3[k]){
      out = check(i + 1, j, k+1);
    }
    else if (S2[j] == S3[k] && S1[i] != S3[k]){
      out = check(i, j+1, k+1);
    }
    else if (S1[i] == S3[k] && S2[j] == S3[k]){
      out = check(i + 1, j, k+1) || check(i, j+1, k+1);
    }
    return hash[vector<int> {i, j, k}] = out;
  }
};