#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

class SolutionNaive {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    return checkCol(board) && checkRow(board) && checkSub(board);
  }

private:
  bool checkRow(const vector<vector<char>>& board){
    for (int i=0; i < board.size(); i++){
      unordered_set<int> S;
      for (int j=0; j < board[0].size(); j++){
        if (board[i][j] == '.') {continue;}
        if (S.find(board[i][j]) != S.end()){return false;}
        else {S.insert(board[i][j]);}
      }
    }
    return true;
  }

  bool checkCol(const vector<vector<char>>& board){
    for (int j=0; j < board[0].size(); j++){
      unordered_set<int> S;
      for (int i=0; i < board.size(); i++){
        if (board[i][j] == '.') {continue;}
        if (S.find(board[i][j]) != S.end()){return false;}
        else {S.insert(board[i][j]);}
      }
    }
    return true;
  }
  
  bool checkSub(const vector<vector<char>>& board){
    for (int i=1; i < board.size(); i += 3){
      for (int j=1; j < board[0].size(); j += 3){
        unordered_set<int> S;
        //cout << i<<",  " << j<< endl;
        for (int it1=-1; it1 !=2; it1++){
          for (int it2=-1; it2 !=2; it2++){
            
            if (board[i + it1][j + it2] == '.') {continue;}
            if (S.find(board[i + it1][j + it2]) != S.end()){return false;}
            else {S.insert(board[i + it1][j + it2]);}
          }
        }
      }
    }

    return true;
  }
};


class Solution{
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i=0; i < board.size(); i++){
      unordered_set<int> setRow, setCol, setgrid;
      for (int j=0; j < board[0].size(); j++){
        if (board[i][j] == '.') {continue;}
        if (setRow.find(board[i][j]) != setRow.end()){return false;}
        else {setRow.insert(board[i][j]);}
        
      }
    }
  }
};

int main()
{ 
  
  Solution* sol;
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << sol ->isValidSudoku(board)<<endl;

  board = vector<vector<char>> {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << sol ->isValidSudoku(board)<<endl;
  return 0;
}