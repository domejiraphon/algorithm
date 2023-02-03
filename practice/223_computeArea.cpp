/*
223. Rectangle Area
Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.

The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).

The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).
*/
class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int interX = lineInter(ax1, ax2, bx1, bx2);
    int interY = lineInter(ay1, ay2, by1, by2);
    //cout << interX<<", "<<interY;
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - interX * interY;
  } 
private:
  int lineInter(int ax1, int ax2, int bx1, int bx2){
    if (bx1 >= ax1)
      return max(min({ax2 - bx1, ax2 - ax1, bx2 - bx1}), 0);
    else
      return max(min({bx2 - ax1, ax2 - ax1, bx2 - bx1}), 0);
  }
};
