/*
1395. Count Number of Teams
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
*/
class Solution {
public:
  int numTeams(vector<int>& rating) {
    int n=rating.size();
    int res=0;
    for (int i=1; i<n-1; i++){
      int less[2] = {}, great[2] = {};
      for (int j=0; j<n; j++){
        if (i == j)
          continue;
        if (rating[j] < rating[i])
          less[j<i]++;
        if (rating[i] < rating[j])
          great[i<j]++;
      }
      res += less[0] * great[0] + less[1] * great[1];
    }
    return res;
      
    
  }
};