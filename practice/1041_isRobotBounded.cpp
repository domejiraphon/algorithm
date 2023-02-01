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
    vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
    int i = 0;
    int x = 0;
    int y = 0;
    for(auto ele: instructions){
      if(ele == 'L'){
        i = (i + 1) % 4;
      }
      else if(ele== 'R'){
        i = (i + 3) % 4;
      }
      else{
        x = x + dir[i][0];
        y = y + dir[i][1];
      }
    }
    return x == 0 && y == 0 || i != 0;
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