/* 2100. Find Good Days to Rob the Bank
You and a gang of thieves are planning on robbing a bank. You are given a 0-indexed integer array security, where security[i] is the number of guards on duty on the ith day. The days are numbered starting from 0. You are also given an integer time.

The ith day is a good day to rob the bank if:

There are at least time days before and after the ith day,
The number of guards at the bank for the time days before i are non-increasing, and
The number of guards at the bank for the time days after i are non-decreasing.
More formally, this means day i is a good day to rob the bank if and only if security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

Return a list of all days (0-indexed) that are good days to rob the bank. The order that the days are returned in does not matter.
*/
class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    vector<int> res;
    int n=security.size();

    if (time == 0){
      for (int i=0; i<n; i++){
        res.push_back(i);
      }
      return res;}
    vector<int> before(n, 0);
    vector<int> after(n, 0);
    
    int startReduce=0, startIncrease=n-1;
    for (int i=0; i<n; i++){
      if (i ==0 || security[i] <= security[i-1]){
        if (i - startReduce >= time)
          before[i] = 1;
      }
      else
        startReduce = i;
      int k = n-i-1;
      if (k == n - 1 || security[k] <= security[k + 1]){
        if (startIncrease - k >= time)
          after[k] = 1;
      }
      else
        startIncrease = k;
    }
   
    for (int i=0; i<n; i++){
      if (before[i] == 1 && before[i] == after[i])
        res.push_back(i);
    }
    return res;
  }
};