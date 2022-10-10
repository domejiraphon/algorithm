#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
   
    unordered_set<char> Set;
    Set.insert(tasks[0]);
    int i(0), n(tasks.size());
    while (i < n){
      if ()
    }
  }
};
int main()
{ 
  vector<char> tasks;
  Solution* sol;

  tasks = {'A','A','A','B','B','B'};
  cout << sol -> leastInterval(tasks, 2) << endl;

  tasks = {'A','A','A','B','B','B'};
  cout << sol -> leastInterval(tasks, 0) << endl;

  tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
  cout << sol -> leastInterval(tasks, 2) << endl;

  return 0;
}