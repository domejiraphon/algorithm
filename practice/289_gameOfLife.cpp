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

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    vector<vector<int>> tmp=board;
    
    for (int i=0; i != board.size(); i++){
      for (int j=0; j != board[0].size(); j++){
        int numLive = countLiveNeighbors(tmp, i, j);
        //cout << numLive <<", ";
        if (tmp[i][j] == 1){
          if (numLive < 2 || numLive >3){board[i][j] = 0;}
        }
        else {
          if (numLive == 3){board[i][j] = 1;}
        }
      } 
    }
    }
private:
  int countLiveNeighbors(const vector<vector<int>>& board, int idx_i, int idx_j){
    int count(0);
   
    for (int i=-1; i != 2; i++){
      for (int j=-1; j != 2; j++){
        if (i == 0 && j == 0){continue;}
        //cout << idx_i + i << ", " << idx_j + j <<endl;
        if (idx_i + i >=0 && idx_i + i <= board.size()-1 &&
            idx_j + j >= 0 && idx_j + j <= board[0].size()-1
            && board[idx_i + i][idx_j + j] == 1){
              count++;
            }
      }
    }
   
    return count;
  }
};

int main()
{
  vector<vector<int>> boards = {{0,1,0}, {0,0,1}, {1,1,1}, {0,0,0}};
  Solution sol;
  sol.gameOfLife(boards);
  
  
  return 0;
}