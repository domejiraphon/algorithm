#include <iostream>
#include <iterator>
#include <map>
#include <stack>
#include <queue>
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
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> S;
    for (auto ele: asteroids){
      if (ele < 0){
        bool bomb(true);
        while (!S.empty() && S.top() > 0){
          if (S.top() < - ele){
            S.pop(); bomb = true;
          }
          else if (S.top() > - ele){
            bomb = false;
            break;
          }
          else {
            S.pop(); bomb = false;
            break;
          }
        }
        if (bomb){S.push(ele);}
      }
      else {
        S.push(ele);
      }
    }
  asteroids.clear();
  while (!S.empty())
  {
    asteroids.insert(asteroids.begin(), S.top());
    S.pop();
  }
  return asteroids;
  }
};

int main()
{ 
  vector<int> asteroids, out;
  Solution* sol;
  asteroids = {5,10,-5};
  out = sol -> asteroidCollision(asteroids);
  print(out);

  asteroids = {8, -8};
  out = sol -> asteroidCollision(asteroids);
  print(out);

  asteroids = {10,2,-5, -20, 8, 4, -2};
  out = sol -> asteroidCollision(asteroids);
  print(out);

  asteroids = {-2, -1, 1, 2};
  out = sol -> asteroidCollision(asteroids);
  print(out);
  return 0;
}