#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class MovingAverage {
  int cur = 0, num;
  deque<int> Q;
public:
    MovingAverage(int size) {
      num = size;
    }
    
    double next(int val) {
      if (Q.size() >= num){
        cur -= Q.front();
        Q.pop_front();
      }
      Q.push_back(val);
      cur += val;
      return (double) cur / Q.size(); 
    }
};
int main()
{ 
  Solution* sol = new Solution();
  cout << sol -> validWordAbbreviation("internationalization", "i12iz4n");
  return 0;
}