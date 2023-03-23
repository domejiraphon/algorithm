/*
1710. Maximum Units on a Truck
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.
*/
bool sortby(vector<int>& a, vector<int>& b){
  return a[1] > b[1];
}
class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), sortby);
    int ans=0;
    int i=0;
    int n=boxTypes.size();
    while (truckSize > 0 && i< n){
      if (truckSize >= boxTypes[i][0]){
        truckSize -=boxTypes[i][0];
        ans += boxTypes[i][0] * boxTypes[i][1];
        i++;
      }
      else {
        ans += truckSize * boxTypes[i][1];
        truckSize = 0;
      }
    }
    return ans;
  }
};