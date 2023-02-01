#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> memo){
  for (auto ele: memo){
    for (auto k: ele){
      cout << k << ", ";
    }
    cout << endl;
  }
}
bool sortby(const vector<int> &a,
              const vector<int> &b){
  if (a[0] == b[0]){return a[1] > b[1];}
  else {
    return a[0] < b[0];
  }
}

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> out;
    sort(people.begin(), people.end(), sortby);
    for(int i = people.size()-1; i>=0; i--){
      out.insert(out.begin() + people[i][1], people[i]);
    }
    return out;
  }
};

int main()
{ 
  
  Solution* sol;
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> out;
  out = sol -> reconstructQueue(people);
  print(out);
 
  
  return 0;
}