#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}
const int mod = 1e9 + 7;
bool sortby(const int &a,
              const int &b){
  return  a > b;}

class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    sort(horizontalCuts.begin(), horizontalCuts.end(), sortby);
    sort(verticalCuts.begin(), verticalCuts.end(), sortby);
    pickRange(h, horizontalCuts); 
    pickRange(w, verticalCuts);
    
    return (int) ((long)h* w % mod);
  }
private: 
  void pickRange(int& range, vector<int> vect){
    vect.insert(vect.begin(), range);
    vect.push_back(0);
    range = 0;
    for (int i=0; i != vect.size()-1; i++){
      range = max(range, vect[i] - vect[i+1]);
    }
  }
};

int main()
{ 
  
  Solution* sol;

  vector<int> horizontalCuts = {1, 2, 4};
  vector<int> verticalCuts = {1, 3};

  cout << sol->maxArea(5, 4, horizontalCuts, verticalCuts)<<endl;
  
  horizontalCuts = vector<int> {5, 2, 6, 3};
  verticalCuts = vector<int> {1, 4};
  cout << sol->maxArea(8, 5, horizontalCuts, verticalCuts)<<endl;
  
  
  horizontalCuts = vector<int> {2};
  verticalCuts = vector<int> {2};
  cout << sol->maxArea(1000000000, 1000000000, horizontalCuts, verticalCuts)<<endl;
  return 0;
}