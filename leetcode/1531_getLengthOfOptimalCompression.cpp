class Solution {
private:
  string S;
  int ans = INT_MAX;
  unordered_set<int> add = {1, 9, 99};
  unordered_map<int, int> hash;
public:
  int getLengthOfOptimalCompression(string s, int k) {
    S = s;
    int out = dp(0, '0', 0, k);
    return out;
  }
private:
  int dp(int idx, char last, int lastNum, int k){
    if (k < 0){return INT_MAX/2;}
    if (idx >= S.size()){return 0;}
    int key = idx * 101 * 27 * 101 + (last - 'a') * 101 * 101 + lastNum * 101 + k;
    if (hash.count(key)){return hash[key];}
    int keep;
    if (S[idx] == last){
      keep = dp(idx + 1, last, lastNum + 1, k);
      if (add.count(lastNum)){keep++;}
    }
    else {
      keep = min(dp(idx + 1, S[idx], 1, k) + 1,
                 dp(idx + 1, last, lastNum, k - 1));
    }
    hash[key] = keep;
    return keep;
  }
};
