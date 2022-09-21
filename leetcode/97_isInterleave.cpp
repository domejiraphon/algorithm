#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != (s1.size() + s2.size())) {return false;}
    vector<vector<bool>> memo(s1.size()+1, vector<bool> (s2.size()+1, false));
    for (int i=0; i != s1.size() + 1; i++){
      for (int j=0; j != s2.size() + 1; j++){
        if (i == 0 && j ==0){memo[0][0] = true; continue;}
        if (i ==0){
          memo[i][j] = memo[i][j - 1] && s3[i + j - 1] == s2[j - 1];
        }
        else if (j ==0){
          memo[i][j] = memo[i - 1][j] && s3[i + j - 1] == s1[i - 1];
        }
        else {
          memo[i][j] = (memo[i][j - 1] && s3[i + j - 1] == s2[j - 1]) || 
                        (memo[i - 1][j] && s3[i + j - 1] == s1[i - 1]);
        }
      }
    }
    return memo[s1.size()][s2.size()];
  }
};
int main()
{ 
  
  Solution* sol;
  
  cout << sol -> isInterleave("aabcc", "dbbca", "aadbbcbcac")<< endl;
  cout << sol -> isInterleave("aabcc", "dbbca", "aadbbbaccc")<< endl;
  
  return 0;
}