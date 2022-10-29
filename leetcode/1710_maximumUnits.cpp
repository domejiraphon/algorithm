#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
  cout << endl;
  }
    
}
bool sortby (vector<int>& a, vector<int>& b){
  return a[1]> b[1];
}
class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), sortby);
    int i(0);
    int count(0);
    print(boxTypes);
    while (truckSize > 0 && i < boxTypes.size()){
      if (truckSize >=boxTypes[i][0]){
        truckSize -= boxTypes[i][0];
        
        count += boxTypes[i][0] * boxTypes[i][1];
        i++;
      }
      else {
        count += boxTypes[i][1] * truckSize;
        break;
      }
      cout << count << endl;

    }
    return count;
  }
};

int main()
{ 
  Solution* sol;
  vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}};
  //cout << sol -> maximumUnits(boxTypes, 4)<< endl;
  boxTypes = {{5,10},{2,5},{4,7},{3,9}};
  cout << sol -> maximumUnits(boxTypes, 10)<< endl;
  return 0;
}