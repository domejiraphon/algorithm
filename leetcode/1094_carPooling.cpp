#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

void print(vector<tuple<char, int, int>> x){
  for (auto row: x){
    cout << get<0>(row) <<",cap: "<< get<1>(row)<<"," << get<2>(row)<<endl;}
  }

bool sortby(const tuple<char, int, int> &a,
              const tuple<char, int, int> &b){
  if (get<2>(a) < get<2>(b)){return true;}
  else if (get<2>(a) == get<2>(b)) {return get<0>(a) < get<0>(b);}
  else {return false;}}
 

class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<tuple<char, int, int>> schedule;
    for (auto elem: trips){
      tuple<char, int, int> cur={'s', elem[0], elem[1]};
      schedule.push_back(cur);
      cur = tuple<char, int, int> {'f', elem[0], elem[2]};
      schedule.push_back(cur);
    }
    sort(schedule.begin(), schedule.end(), sortby);
    for (auto row: schedule){
      if (get<0>(row) == 's'){capacity -= get<1>(row);}
      else if (get<0>(row) == 'f'){capacity += get<1>(row);}
      if (capacity < 0){return false;}
    }
    return true;
  }
  
};

int main()
{
  vector<vector<int>> trips={{2, 1, 5}, {3, 3, 7}};
  
  Solution sol;

  cout<< sol.carPooling(trips, 4)<<endl;
 
  cout<< sol.carPooling(trips, 5)<<endl;
  return 0;
}