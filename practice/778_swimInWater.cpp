/*
778. Swim in Rising Water
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
*/
struct T {
    int cost, x, y;
    T (int a, int b, int c): cost(a), x(b), y(c){}
    bool operator< (const T& com)const {return cost > com.cost;}
};

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    priority_queue<T> pq;
    pq.push(T(grid[0][0], 0, 0));
    int N=grid.size();
    vector<vector<bool>> seen(N, vector<bool>(N, false));
    seen[0][0] = true;
    static int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
    int cost=0;
    while (true){
      auto p = pq.top();
      pq.pop();
      cost = max(cost, p.cost);
      if (p.x == N -1 && p.y == N-1)
        return cost;
      for (auto dir: dirs){
        int newX = p.x + dir[0];
        int newY = p.y + dir[1];
        if (newX >= 0 && newX < N && newY >= 0 && newY < N &&!seen[newX][newY]){
          seen[newX][newY] = true;
          pq.push(T(grid[newX][newY], newX, newY));
        }
      }
    }
    return -1;
  }
};
