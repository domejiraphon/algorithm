/*
935. Knight Dialer

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:
*/
class Solution {
  int mod = pow(10, 9) + 7;
  int dirs[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
public:
  int knightDialer(int n) {
    int res=0;
    vector<vector<vector<long>>> memo(4, vector<vector<long>> (3, vector<long> (n+1, -1)));
    for (int i=0; i<4; i++){
      for (int j=0; j<3; j++){
        if ((i == 3 && j == 0) || (i == 3 && j == 2))
          continue;
        res += count(i, j, n, memo);
      }
    }
    return res;
  }
private:
  long count(int i, int j, int moves, vector<vector<vector<long>>>& memo){
    if (moves == 1)
      return 1;
    if (memo[i][j][moves] != -1)
      return memo[i][j][moves];
    long out=0;
    for (auto dir: dirs){
      int newI = i + dir[0];
      int newJ = j + dir[1];
      if (newI >=0 && newI<4 && newJ >= 0 && newJ<3
          && !(newI == 3 && newJ == 0)
          && !(newI == 3 && newJ == 2)){
        out += count(newI, newJ, moves - 1, memo) % mod;
        
      }
    }
    return memo[i][j][moves] = out;
  }
};
