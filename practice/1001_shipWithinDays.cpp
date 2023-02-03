/*
1011. Capacity To Ship Packages Within D Days
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/
class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int n=weights.size();
    int maxWeight = weights[0];
    int totalWeight =0;
    for (int i=0; i<n; i++){
      maxWeight = max(maxWeight, weights[i]);
      totalWeight += weights[i];
    }
    int l = maxWeight, r = totalWeight;
    
    while (l < r){
      int mid = (l + r)/2;
      if (possible(weights, mid, days))
        r = mid;
      else
        l = mid + 1;
    }
    return r;
    
  }
private:
  bool possible(vector<int>& weights, int limit, int days){
    int n=weights.size();
    int cur =0;
    for (int i=0; i<n; i++){
      cur += weights[i];
      if (cur > limit){
        cur = weights[i];
        days--;
      }
     
    }
    return (days >= 1);
  }
};
