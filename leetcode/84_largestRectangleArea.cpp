#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
class Solution2 {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int right;
    int left;
    int out(0);
    for (int i=0; i < n; i++){
      int cur=0;
      for (int j = i; j < n; j++){
        if (heights[i] <= heights[j]){
          cur++;
        }
        else {break;}
      }
      right = cur;
      cur = 0;
      for (int j = i -1; j >= 0; j--){
        if (heights[i] <= heights[j]){
          cur++;
        }
        else {break;}
      }
      left = cur;
      out = max(out, (right + left)*heights[i]);
    }
    return out;
  }
};

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int out = merge(0, heights.size() - 1, heights);
    return out;
  }
private:
  int merge(int start, int end, vector<int>& heights){
    if (start > end){return 0;}
    int idx(start);
    for (int i=start; i <= end;i++){
      if (heights[idx] > heights[i]){
        idx = i;
      }
    }
    return max(max(heights[idx] * (end - start + 1),
            merge(start, idx - 1, heights)),
            merge(idx + 1, end, heights));
  }
};

int main()
{
  Solution* sol;
  vector<int> heights = {2,4};
  cout << sol -> largestRectangleArea(heights)<< endl; 

  heights = {2,1,5,6,2,3};
  //cout << sol -> largestRectangleArea(heights)<< endl; 
}
