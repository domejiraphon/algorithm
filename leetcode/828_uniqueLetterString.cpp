class Solution {
private:
  int n;
  string S;
public:
  int uniqueLetterString(string s) {
    n = s.size();
    S = s;
    return allSub(0);
  }
private:
  int allSub(int idx){
    if (idx == n){return 0;}
    int count(0);
    for (auto i = idx; i < n; i++){
      cout << idx << i<<":"<<S.substr(idx, i - idx + 1) << endl;
      count += unique(S.substr(idx, i - idx + 1));
      count += allSub(i + 1);
    }
    return count;
  }
  int unique(string s){
    unordered_map<char, int> freq;
    for (auto ch: s){freq[ch]++;}
    int count(0);
    for (auto it=freq.begin(); it != freq.end(); it++){
      if (it -> second == 1){count++;}
    }
    return count;
  }
};
