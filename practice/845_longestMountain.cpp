/*

*/
class Solution {
public:
  int longestMountain(vector<int>& arr) {
    int n=arr.size();
    int left=0, right=0;
    int maxVal=INT_MIN;
    while (right < n){
      while (right < n -1 && arr[right] < arr[right + 1])
        right++;
      int up = right - left;
      
      if (up == 0){
        right++; left = right; continue;
      }
      left = right;
      while (right < n - 1 && arr[right] > arr[right + 1])
        right++;
      int down = right - left;
      if (down == 0){
        right++; left = right; continue;
      }
      
      maxVal = max(maxVal, up + down + 1);
      left = right;
    }
    return maxVal == INT_MIN ? 0 : maxVal;
  }
};
