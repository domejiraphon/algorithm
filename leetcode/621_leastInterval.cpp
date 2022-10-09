#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <unordered_set>
#include <stack>
#include <tuple>

using namespace std;

void print(vector<int> x){
  for (auto elem: x){
    cout << elem <<', ';}
  cout << endl;
}
class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
      
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