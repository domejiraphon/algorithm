/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/
class Solution {
private:
  vector<int> Heights;
public:
  int largestRectangleArea(vector<int>& heights) {
    Heights = heights;
    return subProblem(0, heights.size() - 1);
  }
private:
  int subProblem(int start, int end){
    if (start > end){return 0;}
    int minIdx = start;
    for (int i=start+1; i<=end; i++){
      if (Heights[minIdx] > Heights[i]){
        minIdx = i;
      }
    }
    return max({Heights[minIdx] * (end - start + 1),
              subProblem(start, minIdx - 1),
              subProblem(minIdx + 1, end)});
  }
};

class Solution {
private:
  vector<int> Heights;
public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> S;
    S.push(-1);
    heights.push_back(0);
    int n=heights.size();
    int maxVal = 0;
    for (int i=0; i<n; i++){
      while (S.top() != -1 && heights[S.top()] >= heights[i]){
        int current_height = heights[S.top()];
        S.pop();
        int current_width = i - S.top() - 1;
        maxVal = max(maxVal, current_height * current_width);
      }
      S.push(i);
    }
    return maxVal;
  }
};