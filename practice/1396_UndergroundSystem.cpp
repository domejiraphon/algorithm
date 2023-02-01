#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;
class UndergroundSystem {
private:
  unordered_map<int, pair<string, int>> customer;
  unordered_map<string, pair<int, int>> time;
public:
  UndergroundSystem() {

  }

  void checkIn(int id, string stationName, int t) {
    customer[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    pair<int, int> prev = time[customer[id].first + " " + stationName];
    time[customer[id].first + " " +stationName] = 
      {prev.first + t - customer[id].second,
       prev.second + 1};
      
  }

  double getAverageTime(string startStation, string endStation) {
    pair<int, int> prev = time[startStation + " " + endStation];
    return (double) prev.first / prev.second; 
  }
};
int main()
{
  UndergroundSystem* obj = new UndergroundSystem();
  obj->checkIn(id,stationName,t);
  obj->checkOut(id,stationName,t);
  double param_3 = obj->getAverageTime(startStation,endStation);
  return 0;
}