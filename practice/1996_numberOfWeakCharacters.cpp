#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool sortby(const vector<int> &a,
              const vector<int> &b){
  return  (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);}

void print(const vector<vector<int>>& vect){
  for (auto row: vect){
    for (auto ele: row){
      cout << ele<<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), sortby);
    int size = properties.size();
    int count(size-1); int maxDefense(properties[size - 1][1]);
    int maxAttack(properties[size - 1][0]);
    for (int i=size - 2; i !=-1; i--){
      if (maxDefense <= properties[i][1]){
        count--;
        maxDefense = properties[i][1];
      }
      if (properties[i][0] == maxAttack){count--;}
    }
    return count;
  }
  
};

int main()
{
  vector<vector<int>> properties {{1, 5}, {10, 4}, {4, 3}};
  Solution sol;
  //cout << sol.numberOfWeakCharacters(properties)<< endl;

  vector<vector<int>> properties2 {{7, 9}, {10, 7}, {6, 9}, {10, 4}, {7, 5}, {7, 10}};
  cout << sol.numberOfWeakCharacters(properties2)<< endl;

  vector<vector<int>> properties3 {{1, 1}, {1, 2} , {2, 1}, {2, 2}};
  //cout << sol.numberOfWeakCharacters(properties3)<< endl;
  
  return 0;
}