/*
599. Minimum Index Sum of Two Lists
Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.
*/
class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> index;
    int n=list1.size();
    for (int i=0; i<n; i++)
      index[list1[i]] = i;
    map<int, vector<string>> out;
    int m=list2.size();
    for (int i=0; i<m; i++){
      if (index.count(list2[i]))
        out[i + index[list2[i]]].push_back(list2[i]);
    }
    auto it=out.begin();
    return it -> second;
  }
};
