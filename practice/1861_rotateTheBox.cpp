/*
1861. Rotating the Box
You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

A stone '#'
A stationary obstacle '*'
Empty '.'
The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

Return an n x m matrix representing the box after the rotation described above.
*/
class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int n=box.size();
    int m=box[0].size();
    for (int i=0; i<n; i++){
      for (int j=m-1; j >=0 ; j--){
        if (box[i][j] == '#'){
          int newJ = j+1;
          while (newJ < m && box[i][newJ] == '.')
            newJ++;
          newJ--;
          box[i][newJ] = box[i][j];
          if (newJ != j)
            box[i][j] = '.';
        }
      }
    }
    vector<vector<char>> rotatedBox = rotate(box);
    return rotatedBox;
    //return box;
  }
private:
  vector<vector<char>> rotate(vector<vector<char>>& box){
    int n=box.size();
    int m=box[0].size();
    vector<vector<char>> rotatedBox(m, vector<char>(n));
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        rotatedBox[j][n-1-i] = box[i][j];
      }
    }
    return rotatedBox;
  }

};