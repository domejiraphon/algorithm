/*
1122. Relative Sort Array

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/
class Solution {
public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    int freq[1001] = {};
    int n=arr1.size();
    for (int i=0; i<n; i++)
      freq[arr1[i]]++;
    vector<int> out;
    n=arr2.size();
    for (int i=0; i<n; i++){
      for (int j=0; j<freq[arr2[i]]; j++)
        out.push_back(arr2[i]);
      freq[arr2[i]] = 0;
    }
    for (int i=0; i<1001; i++){
      if (!freq[i])
        continue;
      for (int j=0; j<freq[i]; j++)
        out.push_back(i);
    }
    return out;
  }
};
