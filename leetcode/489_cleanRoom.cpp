/*
489. Robot Room Cleaner
You are controlling a robot that is located somewhere in a room. The room is modeled as an m x n binary grid where 0 represents a wall and 1 represents an empty slot.

The robot starts at an unknown location in the room that is guaranteed to be empty, and you do not have access to the grid, but you can move the robot using the given API Robot.

You are tasked to use the robot to clean the entire room (i.e., clean every empty cell in the room). The robot with the four given APIs can move forward, turn left, or turn right. Each turn is 90 degrees.

When the robot tries to move into a wall cell, its bumper sensor detects the obstacle, and it stays on the current cell.

Design an algorithm to clean the entire room using the following APIs:

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
Note that the initial direction of the robot will be facing up. You can assume all four edges of the grid are all surrounded by a wall.

 

Custom testing:

The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the four mentioned APIs without knowing the room layout and the initial robot's position.
*/
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
  int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
  void cleanRoom(Robot& robot) {
    set<pair<int, int>> visited;
    backtrack(0, 0, 0, visited, robot);
  }
private:
  void backtrack(int row, int col, int d, set<pair<int, int>>& visited, Robot& robot){
    visited.insert({row, col});
    robot.clean();
    for (int i=0; i<4; i++){
      int idx = (i + d)% 4;
      int nRow = row + dirs[idx][0];
      int nCol = col + dirs[idx][1];
      if (!visited.count({nRow, nCol}) && robot.move()){
        backtrack(nRow, nCol, idx, visited, robot);
        goBack(robot);
      }
      robot.turnRight();
    }
  }
  void goBack(Robot& robot){
    robot.turnRight();
    robot.turnRight();
    robot.move();
    robot.turnRight();
    robot.turnRight();
  }
};
