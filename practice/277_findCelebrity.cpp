#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int findCelebrity(int n) {
    for (int i=1; i<=n; i++){
      bool found(true);
      for (int j =1; j <=n; j++){
        if (i == j) {continue;}
        found = found && (!knows(i, j) || knows(j, i));
        if (!found){break;}
      }
      if (found){return i;}
    }
    return -1;
  }
  bool knows(int a, int b){return true;}
};

int main()
{ 
  Solution* sol;
  
  cout << sol -> findCelebrity(3)<< endl;

  return 0;
}