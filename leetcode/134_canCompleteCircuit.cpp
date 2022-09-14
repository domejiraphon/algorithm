#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
void print(vector<tuple<int, int, int>> x){
  for (auto row :x){
    cout << get<0>(row) << ", " << get<2>(row)<<endl;
  }
}
bool sortby(const tuple<int, int, int> &a,
              const tuple<int, int, int> &b){
  if (get<2>(a) < get<2>(b)) {return true;}
  else if (get<2>(a) == get<2>(b)) {return get<1>(a) > get<1>(b);}
  else {return false;}}

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    vector<tuple<int, int, int>> bonus;
    for (int i=0; i != gas.size(); i++){
      tuple<int, int, int> cur = {i, cost[i], gas[i] - cost[i]};
      bonus.push_back(cur);
    }
    sort(bonus.begin(), bonus.end(), sortby);
   
    int startIdx= get<0>(bonus[0]);
    startIdx = 3;
    int tank=gas[startIdx];
  
    for (int i=1; i != gas.size(); i++){
      int newIdx = startIdx +i;
     
      if (newIdx >= gas.size()){newIdx %= gas.size();}
      
      tank += gas[newIdx] - cost[newIdx];
      
      if (tank < 0) {return -1;}
    }
    
    return startIdx;
  }
};

int main()
{
  vector<int> gas = {1,2,3,4,5};
  vector<int> cost = {3,4,5,1,2};
  Solution sol;
  cout << sol.canCompleteCircuit(gas, cost) << endl;

  gas = vector<int> {2,3,4};
  cost = vector<int> {3,4,3};
  //cout << sol.canCompleteCircuit(gas, cost) << endl;
  
  return 0;
}