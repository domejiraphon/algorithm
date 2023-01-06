/* 1762. Buildings With an Ocean View
There are n buildings in a line. 
You are given an integer array heights of size n that represents the heights of the buildings in the line.

The ocean is to the right of the buildings. 
A building has an ocean view if the building can see the ocean without obstructions. 
Formally, a building has an ocean view if all the buildings to its right have a smaller height.

Return a list of indices (0-indexed) of buildings that have an ocean view, sorted in increasing order.
*/
class Solution {
public:
  vector<int> findBuildings(vector<int>& heights) {
    int n=heights.size();
    vector<int> res={n - 1};
    int prev = 0;
    for (int i=n-2; i >= 0; i--){
      prev = max(prev, heights[i+1]);
      if (prev < heights[i])
        res.push_back(i);
    }
    int left=0, right = res.size() - 1;
    while (left < right)
      swap(res[left++], res[right--]);
    return res;
    
  }
};