/*
717. 1-bit and 2-bit Characters
We have two special characters:

The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.
*/
class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int n=bits.size();
    vector<int> memo(n, -1);
    return dp(bits, 0, n, memo);
  }
private:
  bool dp(vector<int>& bits, int i, int& n, vector<int>& memo){
    if (i == n - 1)
      return true;
    if (i > n - 1)
      return false;
    if (memo[i] != -1)
      return memo[i] == 1;
    bool out;
    if (bits[i] == 1)
      out = dp(bits, i + 2, n, memo);
    else
      out = dp(bits, i + 1, n, memo);
    return memo[i] = out;
  }
};
