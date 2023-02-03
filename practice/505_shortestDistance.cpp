/*
505. The Maze II
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).
*/
class Solution {
public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    queue<pair<int, int>> Q;
    Q.push({start[0], start[1]});

    int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int n=maze.size();
    int m=maze[0].size();
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
 
    dist[start[0]][start[1]] = 0;
    while (!Q.empty()){
      
      pair<int, int> cur = Q.front();
      
      Q.pop();
      for (auto dir: dirs){
        int newI = cur.first + dir[0];
        int newJ = cur.second + dir[1];
        int curD = 0;
        if (newI < 0 || newI >= n || newJ < 0 || newJ >= m || maze[newI][newJ] == 1)
          continue;


        while (0 <= newI && newI < n && 0<= newJ && newJ < m && maze[newI][newJ] == 0){
          newI += dir[0];
          newJ += dir[1];
          curD++;
        }
        newI -= dir[0];
        newJ -= dir[1];

        if (dist[newI][newJ] > dist[cur.first][cur.second] + curD){
          dist[newI][newJ] = dist[cur.first][cur.second] + curD;

          Q.push({newI, newJ});
        }
            
        
      }
      
    }
    return dist[destination[0]][destination[1]] != INT_MAX ? dist[destination[0]][destination[1]] : -1;
  }
};
