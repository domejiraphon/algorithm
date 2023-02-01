/*
688. Knight Probability in Chessboard
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.


*/
class Solution {
public:
  double knightProbability(int n, int k, int row, int column) {
    int dirs[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
    vector<vector<double>> memo(n, vector<double>(n, 0.0));
    memo[row][column] = 1;
    while (k > 0){
      vector<vector<double>> memo2(n, vector<double>(n, 0));
      for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
          for (auto dir: dirs){
            int newRow = i + dir[0];
            int newCol = j + dir[1];
            if (newRow >=0 && newRow <n && newCol >= 0 && newCol < n)
              memo2[newRow][newCol] += memo[i][j] / 8;
          }
        }
      }
      k--;
      memo = memo2;
    }
    double sum = 0;
    for (int i=0; i<n; i++){
      for (int j=0; j<n; j++){
        sum += memo[i][j];
      }
    }
    return sum;
  }
};
