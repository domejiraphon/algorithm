#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

void print(map<int, tuple<int, int>> row){
  for (auto it = row.begin(); it != row.end(); it++){
    cout << it -> first << ": (" << get<0>(it -> second);
    cout << ", " << get<1>(it -> second) << ")"<<endl;
  }
}

class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int low(0), high(people.size() - 1);
    int count(0);
    while (low <= high)
    {
      if (low == high){count++; break;}
      if (people[low] + people[high] <= limit){
        low++; high--; 
      }
      else {
        high--;
      }
      count++;
    }
    return count;
  }
};

int main()
{
  vector<int> people={1, 2};
  Solution sol;
  cout << sol.numRescueBoats(people, 3)<< endl;

  people = vector<int> {3,2,2,1};
  cout << sol.numRescueBoats(people, 4)<< endl;

  people = vector<int> {3,5,3,4};
  cout << sol.numRescueBoats(people, 5)<< endl;
  
  return 0;
}