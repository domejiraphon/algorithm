/*
1094. Car Pooling
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.
*/
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    map<int, int> map;
    for (auto trip: trips){
      map[trip[1]] += trip[0];
      map[trip[2]] += -trip[0];
    }
    int cur=0;
    for (auto it: map){
      cur += it.second;
      if (cur > capacity)
        return false;
    }
    return true;
  }
};

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
