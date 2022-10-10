#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
using namespace std;

class Solution {
public:
  bool isRobotBounded(string instructions) {
    pair<int, int> dir = {1, 0};
    pair<int, int> end = {0, 0};
    map<pair<int, int>, pair<int, int>> dirLTable, dirRTable;
    dirLTable[{1, 0}] = {0, -1}; dirLTable[{0, -1}] = {-1, 0}; 
    dirLTable[{-1, 0}] = {0, 1}; dirLTable[{0, 1}] = {1, 0}; 

    dirRTable[{1, 0}] = {0, 1}; dirRTable[{0, 1}] = {-1, 0}; 
    dirRTable[{-1, 0}] = {0, -1}; dirRTable[{0, -1}] = {1, 0}; 
    for (auto ele: instructions){
      if (ele == 'G'){
        end.first += dir.first;
        end.second += dir.second;
      }
      else if (ele == 'L'){
        dir = dirLTable[dir];
      }
      else if (ele == 'R'){
        dir = dirRTable[dir];
      }
    }
    if (end.first == 0 && end.second == 0){
      return true;
    }
    else if (check(end, dir)){
        return true;
      }
    return false;
  }
private:
  bool check(pair<int, int> end, pair<int, int> dir){
    float norm = pow(pow(end.first, 2) + pow(end.second, 2), 0.5);
    float dot = (end.first * dir.first + end.second * dir.second) / norm;

    return (dot != 1.0);
  }
};

int main()
{ 
  
  Solution* sol;
  /*
  cout << sol -> isRobotBounded("GGLLGG")<< endl;
  cout << sol -> isRobotBounded("GG")<< endl;
  cout << sol -> isRobotBounded("GL")<< endl;*/
  cout << sol -> isRobotBounded("LLGRL")<< endl;

  return 0;
}