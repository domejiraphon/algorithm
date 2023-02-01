/* 1864. Minimum Number of Swaps to Make the Binary String Alternating
Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.
*/
class Solution {
public:
  int minSwaps(string s) {
    int freq[2];
    memset(freq, 0, sizeof(freq));
    int n=s.size();
    for (int i=0; i< n; i++)
      freq[s[i] - '0']++;
    
    if (abs(freq[0] - freq[1]) > 1)
      return -1;
    int count[2];
    memset(count, 0, sizeof(count));
    for (int i=0; i<n; i+=2){
      count[0] += s[i] != '0';
      count[1] += s[i] != '1';
    }
    if (freq[0] == freq[1])
      return min(count[0], count[1]);
    
    return freq[0] > freq[1] ? count[0] : count[1];
  }
};