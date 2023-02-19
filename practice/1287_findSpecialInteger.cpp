/*
1287. Element Appearing More Than 25% In Sorted Array
Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.
*/
class Solution {
public:
  int findSpecialInteger(vector<int>& arr) {
    int n=arr.size();
    int count=1;
    for (int i=1; i<n; i++){
      if (arr[i] == arr[i-1])
        count++;
      else
        count = 1;
      if (count > (int) n /4)
        return arr[i];
    }
    return arr[0];
  }
};
