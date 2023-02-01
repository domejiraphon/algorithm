#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<int> vec){
  for (auto ele: vec){
    cout << ele << ", ";
  }
  cout << endl;
}

class Solution {
public:
  int findTheWinner(int n, int k) {
    vector<int> circle(n);
    for (int i=0; i < n; i++){circle[i] = i +1;}
    int startIdx(0), stopIdx(0);
    while(circle.size() > 1){
      stopIdx = (k + startIdx - 1) % circle.size();
      circle.erase(circle.begin() + stopIdx);
      startIdx = (stopIdx) % circle.size();
    }
    return circle[0];
  }
};

int main()
{ 
  Solution* sol;
  cout << sol -> findTheWinner(5, 2)<< endl;
  cout << sol -> findTheWinner(6, 5)<< endl;
  return 0;
}