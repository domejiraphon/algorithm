#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
void print(set<vector<int>> x){
  for(auto it=x.begin(); it != x.end(); it++){
    for (auto ele: *it){
      cout << ele << ", ";
    }
    cout << endl;
  }
}
class Solution {
  vector<int> weight;
public:
    Solution(vector<int>& w) {
      weight = w;
    }
    
    int pickIndex() {
        
    }
};

int main()
{
  vector<int> w ={1, 3};
  Solution* obj = new Solution(w);
  int param_1 = obj->pickIndex();
  return 0;
}