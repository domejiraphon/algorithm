class Solution {
private:
  int end1, end2;
  string t1, t2;
  vector<vector<int>> dp;
public:
  int longestCommonSubsequence(string text1, string text2) {
    end1 = text1.size(); end2 = text2.size();
    t1 = text1; t2 = text2;
    dp.resize(end1+1, vector<int> (end2+1, -1));
    return longest(0, 0);
  }
private:
  int longest(int start1, int start2){
    if (start1>= end1 || start2 >= end2){return 0;}
    if (dp[start1][start2] != -1){
      return dp[start1][start2];
    }
    int out;
    if (t1[start1] == t2[start2]){
      out = 1+ longest(start1+1, start2 + 1);
    }
    else {
      out = max(longest(start1, start2 + 1),
                longest(start1+1, start2));
    }
    dp[start1][start2] = out;
    return out;
  }
};
