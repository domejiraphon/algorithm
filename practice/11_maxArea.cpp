/* 11. Container With Most Water
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
class Solution {
public:
  int maxArea(vector<int>& height) {
    int n=height.size();
    int left = 0, right = n -1;
    int area=0;
    while (left < right){
      area = max(area, (right - left) * min(height[right], height[left]));
      if (height[right] < height[left]) right--;
      else left++;
    }
    return area;
  }
};