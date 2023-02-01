#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  bool winnerOfGame(string colors) {
    int n=colors.size();
    int roundA(0), roundB(0);
    for (int i=0; i < n - 2; i++){
      if (colors[i] == colors[i + 1] &&
         colors[i + 1] == colors[i + 2] &&
         colors[i]){
          if (colors[i] == 'A'){roundA++;}
          else if (colors[i] == 'B'){roundB++;}
      }
    }
    return (roundA > roundB) ? true : false;
  }
};

int main()
{ 

  Solution* sol;
  cout << sol -> winnerOfGame("AAABABB") << endl;
  cout << sol -> winnerOfGame("AA") << endl;
  cout << sol -> winnerOfGame("ABBBBBBBAAA") << endl;

  return 0;
}