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
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem<<", ";
    }
    cout << endl;
  }
}

class Point{
public:
  int x;
  int y;
  int dist;
  Point(int val_x, int val_y){
    x = val_x; y = val_y;
    dist = pow(x, 2)+ pow(y, 2);
  }
  int getDist(){
    return dist;
  }
};

class myComparator{
public:
  int operator() (Point& p1, Point& p2){return p1.getDist() > p2.getDist();}
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue <Point, vector<Point>, myComparator> Heap;
      for (int i=0; i != points.size(); i++){
        Heap.push(Point(points[i][0], points[i][1]));
      }
      points.clear();
      int counter(0);
      while (!Heap.empty()){
        Point p = Heap.top();
       
        points.push_back(vector<int> {p.x, p.y});
        Heap.pop();
        counter++;
        if (counter==k){break;}
      }
      
      return points;
    }
};

int main()
{
  vector<vector<int>> intervals={{3, 3}, {5, -1}, {-2, 4}};
  
  Solution sol;
  vector<vector<int>> out;
  out = sol.kClosest(intervals, 2);
  print(out);
  return 0;
}