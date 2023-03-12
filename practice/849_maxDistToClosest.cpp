/*
849. Maximize Distance to Closest Person
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
*/
class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    int n=seats.size();
    vector<int> left(n, INT_MAX);
    int prev=-1;
    for (int i=0; i<n; i++){
      if (seats[i] == 1)
        prev = i;
      
      if (prev != -1)
        left[i] = i - prev;
    }
    prev = -1;
    for (int i=n-1; i>=0; i--){
      if (seats[i] == 1)
        prev = i;
      
      if (prev != -1)
        left[i] = min(left[i], prev - i);
    }
    
    int res=0;
    for (int i=0; i<n; i++)
      res = max(res, left[i]);
    return res;
  }
};
