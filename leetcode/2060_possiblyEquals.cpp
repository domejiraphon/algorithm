/* 2060. Check if an Original String Exists Given Two Encoded Strings
An original string, consisting of lowercase English letters, can be encoded by the following steps:

Arbitrarily split it into a sequence of some number of non-empty substrings.
Arbitrarily choose some elements (possibly none) of the sequence, and replace each with its length (as a numeric string).
Concatenate the sequence as the encoded string.
For example, one way to encode an original string "abcdefghijklmnop" might be:

Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
Choose the second and third elements to be replaced by their lengths, respectively. The sequence becomes ["ab", "12", "1", "p"].
Concatenate the elements of the sequence to get the encoded string: "ab121p".
Given two encoded strings s1 and s2, consisting of lowercase English letters and digits 1-9 (inclusive), return true if there exists an original string that could be encoded as both s1 and s2. Otherwise, return false.

Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.
*/
class Solution {
  bool visited[41][41][2000];
public:
  bool possiblyEquals(string& s1, string& s2, int i=0, int j=0, int diff=0) {
    auto nextNumber = 
      [&](string& s, int& p, int sign){
        int cur=0;
        while (p<s.size() && isdigit(s[p])){
          cur = 10 * cur + (s[p++] - '0');
          if (possiblyEquals(s1, s2, i, j, diff + sign * cur))
            return true;
        }
        return false;
      };
    
    if (i == s1.size() && j == s2.size())
      return diff == 0;
    if (!visited[i][j][1000 + diff]) {
        visited[i][j][1000 + diff] = true;
      if (i < s1.size() && isdigit(s1[i]))
        return nextNumber(s1, i, -1);
      if (j < s2.size() && isdigit(s2[j]))
        return nextNumber(s2, j, 1);
      if (diff > 0)
        return i < s1.size() && possiblyEquals(s1, s2, i + 1, j, diff - 1);
      if (diff < 0)
        return j < s2.size() && possiblyEquals(s1, s2, i, j + 1, diff + 1);
      return i < s1.size() && j < s2.size() && s1[i] == s2[j] && possiblyEquals(s1, s2, i + 1, j + 1, diff);
    }
    return false;
  }
};
