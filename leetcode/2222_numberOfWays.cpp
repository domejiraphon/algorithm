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