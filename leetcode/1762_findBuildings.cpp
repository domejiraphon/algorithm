#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;
void print(vector<int> x){
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
}

class Solution {
public:
  vector<int> findBuildings(vector<int>& heights) {
    int _max = heights[heights.size() - 1];
    stack<int> S;
    S.push(heights.size() - 1);
    for (int i= heights.size() - 2; i >= 0; i--){
      if (heights[i] > _max){
        S.push(i);
        _max = max(_max, heights[i]);
      }
    }
    heights.clear();
    while (!S.empty()){
      heights.push_back(S.top());
      S.pop();
    }
    return heights;
  }
};

int main()
{ 
  
  Solution* sol;
  vector<int> out;

  vector<int> heights = {4,2,3,1};
  out = sol -> findBuildings(heights);
  print(out);
  return 0;
}