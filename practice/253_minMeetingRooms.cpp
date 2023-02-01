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

void print(vector<tuple<char, int>> x){
  for (auto row: x){
    cout << get<0>(row) <<", "<< get<1>(row)<<endl;}
  }

bool sortby(const tuple<char, int> &a,
              const tuple<char, int> &b){
  if (get<1>(a) < get<1>(b)){return true;}
  else if (get<1>(a) == get<1>(b)) {return get<0>(a) < get<0>(b);}
  else {return false;}}
 

class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<tuple<char, int>> schedule;
    for (auto elem: intervals){
      tuple<char, int> cur={'s', elem[0]};
      schedule.push_back(cur);
      cur = tuple<char, int> {'f', elem[1]};
      schedule.push_back(cur);
    }
    sort(schedule.begin(), schedule.end(), sortby);
    int count(0);
    int minRooms(0);
    print(schedule);
    for (auto row: schedule){
      if (get<0>(row) == 's'){count++;}
      else if (get<0>(row) == 'f'){count--;}
      minRooms = max(count, minRooms);
    }
    return minRooms;
  }
};

int main()
{
  vector<vector<int>> intervals={{2,11},{6,16},{11,16}};
  
  Solution sol;

  cout<< sol.minMeetingRooms(intervals)<<endl;
 
  return 0;
}