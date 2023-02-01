class Solution {
private:
  unordered_map<string, bool> hash;
public:
  bool isScramble(string s1, string s2) {
    string key = s1 + "_" + s2;
    if (hash.count(key)){return hash[key];}
    int n=s1.size();
    bool out(false);
    if (s1 == s2){out = true;}
    else {
      for (int i=1; i<n; i++){
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
          out = true;
        }
        if (!out && isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i))){
          out = true;
        }
      }
    }
    
    return hash[key] = out;
  }
};


