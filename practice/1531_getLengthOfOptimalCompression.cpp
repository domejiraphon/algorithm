/*
1531. String Compression II

Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.


*/
class Solution {
  unordered_set<int> nine ={1, 9, 99};
public:
  int getLengthOfOptimalCompression(string s, int k) {
    int n=s.size();
    unordered_map<int, int> memo;
    return dp(s, 0, '/', 0, k, n, memo);
  }
private:
  int dp(string& s, int idx, char lastCha, int lastNum, int k, int& n, unordered_map<int, int>& memo){
    if (k < 0)
      return INT_MAX /2;
    if (idx ==n)
      return 0;
    int key = idx * 101 * 27 * 101 + (lastCha - 'a') * 101 * 101 + lastNum * 101 + k;
    if (memo.count(key))
      return memo[key];
    int out=INT_MAX;
    if (s[idx] == lastCha){
      out = dp(s, idx+1, lastCha, lastNum + 1, k, n, memo);
      if (nine.count(lastNum))
        out++;
    }
    out = min({out, 
              dp(s, idx+1, lastCha, lastNum, k-1, n, memo),
              1 + dp(s, idx+1, s[idx], 1, k, n, memo)});
    return memo[key] = out;
  }
};