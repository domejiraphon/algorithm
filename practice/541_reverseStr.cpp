class Solution {
public:
  string reverseStr(string s, int k) {
    int start = 0, end = k - 1;
    int n=s.size();
    while (start < n){
      int l = start;
      int r = min(end, n - 1);
      while (l < r)
        swap(s[l++], s[r--]);
      start += 2 * k;
      end += 2 * k;
    }
    return s;
  }
};
