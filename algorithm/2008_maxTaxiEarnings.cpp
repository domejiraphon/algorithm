#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
void print(vector<long long> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
bool sortby(const vector<int> &a,
              const vector<int> &b){
  return  (a[1] < b[1]);}
class Solution {
public:
  long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    vector<long long> memo(rides.size());
    sort(rides.begin(), rides.end(), sortby);

    for (int i =0; i < rides.size(); i++){
      memo[i] = rides[i][1] - rides[i][0] + rides[i][2];
    }
    
    for (int i=0; i < rides.size(); i++){
      for (int j=0; j < i; j++){
        if (rides[j][1] <= rides[i][0]){
          memo[i] = max(memo[i], 
                  memo[j] + rides[i][1] - rides[i][0] + rides[i][2]);
        }
      }
    }
    long long out(memo[0]);
    for (auto ele: memo){
      out = max(out, ele);
    }
    return out;
  }
};

int main()
{
  vector<vector<int>> rides = {{2,5,4},
                                {1,5,1}};
  
  Solution sol;
  cout << sol.maxTaxiEarnings(5, rides) << endl;

  rides = {{1,6,1}, {3,10,2}, {10,12,3}, 
          {11,12,2}, {12,15,2}, {13,18,1}};
  cout << sol.maxTaxiEarnings(20, rides) << endl;

  rides = {{2,3,6}, {8,9,8}, {5,9,7}, 
            {8,9,1}, {2,9,2}, {9,10,6}, 
            {7,10,10}, {6,7,9}, {4,9,7}, {2,3,1}};
  cout << sol.maxTaxiEarnings(10, rides) << endl;
  return 0;
}