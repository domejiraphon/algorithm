#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}
bool sortby(const tuple<char, int> &a,
              const tuple<char, int> &b){
  if (get<1>(a) < get<1>(b)){return true;}
  else if (get<1>(a) == get<1>(b)) {return get<0>(a) > get<0>(b);}
  else {return false;}}

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<tuple<char, int>> schedule;
    for (auto elem: intervals){
      tuple<char, int> cur={'s', elem[0]};
      schedule.push_back(cur);
      cur = tuple<char, int> {'f', elem[1]};
      schedule.push_back(cur);
    }
    sort(schedule.begin(), schedule.end(), sortby);
    int start(0), end(0);
    intervals.clear();
    queue<int> Q;
    int count(0);
    for (auto it : schedule){
      if (get<0>(it) == 's'){
        count++;
        Q.push(get<1>(it));
      }
      else {
        count--;
      }
      if (count == 0){
        vector<int> cur = {Q.front(), get<1>(it)};
        intervals.push_back(cur);
        Q = queue<int> {};
      }
    }
    return intervals;
  }
};
int main()
{
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}}, out;
  Solution sol;
  out = sol.merge(intervals);
  print(out);
  cout <<endl;

  intervals = vector<vector<int>> {{1, 4}, {4, 5}};
  out = sol.merge(intervals);
  print(out);
  
  
  return 0;
}