/*
You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
Return the number of valid ways to select 3 buildings.
*/
class Solution {
public:
  long long numberOfWays(string s) {
    int n=s.size();
    int before[n][2], after[n][2];
    memset(before, 0, sizeof(before));
    memset(after, 0, sizeof(after));
    before[0][0] = (s[0] == '0');
    before[0][1] = (s[0] == '1');

    after[n-1][0] = (s[n-1] == '0');
    after[n-1][1] = (s[n-1] == '1');
    for (int i=1; i<n; i++){
      before[i][0] = (s[i] == '0') ? before[i-1][0] + 1: before[i - 1][0];
      before[i][1] = (s[i] == '1') ? before[i-1][1] + 1: before[i - 1][1];

      after[n-i-1][0] = (s[n-i-1] == '0') ? after[n-i][0] + 1: after[n-i][0];
      after[n-i-1][1] = (s[n-i-1] == '1') ? after[n-i][1] + 1: after[n-i][1];
        
    }
    long long res=0;
    for (int i=1; i<n-1; i++){
      if (s[i] == '0')
        res += (long long) before[i][1] * after[i][1];
      else
        res += (long long) before[i][0] * after[i][0];
    }
    return res;
  }
};

class Solution {
  int n;
  string buildings;
  vector<vector<long long>> memo;
public:
  long long numberOfWays(string s) {
    buildings = s;
    n = s.size();
    memo.resize(n + 1, vector<long long> (3, -1));
    return numBuildings(-1, 0);
  }
private:
  long long numBuildings(int start, int nums){
    if (nums == 3){return 1;}
    if (nums > 3 || start >= n){return 0;}
    if (memo[start + 1][nums] != -1)
      return memo[start + 1][nums];
    long long res=0;
    for (int i=start + 1; i<n; i++){
      if (start == -1 || buildings[i] != buildings[start])
        res += numBuildings(i, nums + 1);
    }
    
    return memo[start + 1][nums] = res;
  }
};