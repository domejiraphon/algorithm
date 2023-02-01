#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}


class myComparator{
public:
  int operator() (int a, int b){return a > b;}};

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, myComparator> minHeapLadder;
    int curLadder(0);
    int furthest(0);
    for (int i =0; i != heights.size()-1; i++){
      if (heights[i+1] > heights[i]){
        if (curLadder < ladders){
          minHeapLadder.push(heights[i+1] - heights[i]);
          curLadder++;
        }
        else{
          if (!minHeapLadder.empty()){
            int usedBricks = minHeapLadder.top();
            if (usedBricks < (heights[i+1] - heights[i])){
              minHeapLadder.pop();
              minHeapLadder.push(heights[i+1] - heights[i]);
              if (bricks >= usedBricks){bricks -= usedBricks;}
              else {return furthest;}
            }
            else{
              if (bricks >= heights[i+1] - heights[i]){
                bricks -= heights[i+1] - heights[i];}
              else {return furthest;}
          }
          }
          else{
            if (bricks >= heights[i+1] - heights[i]){
              bricks -= heights[i+1] - heights[i];}
            else {return furthest;}
          }
        }
      }
      furthest++;
     
    }
    return furthest;
  }
};

int main()
{
  vector<int> heights = {4,2,7,6,9,14,12};
  
  Solution sol;
  cout << sol.furthestBuilding(heights, 5, 1) << endl;

  heights = vector<int> {4,12,2,7,3,18,20,3,19};
  cout << sol.furthestBuilding(heights, 10, 2) << endl;

  heights = vector<int> {1, 4, 8, 8};
  cout << sol.furthestBuilding(heights, 3, 1) << endl;
  
  
  return 0;
}