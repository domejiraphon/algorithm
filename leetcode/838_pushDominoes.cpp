#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    int left, right;
    string tmp=dominoes;
    for (int i=1; i < n; i++){
      if (dominoes[i] == '.'){
        left = i -1;
        right = i+1;
        while (left >=0 && right < n){
          if (dominoes[left] != '.' && dominoes[right] != '.'){break;}
          if (dominoes[left] == '.'){left--;}
          if (dominoes[right] == '.'){right++;}
        }
        cout << left << right; exit(0);
        if (dominoes[left] == 'L' && dominoes[right] == 'L'){tmp[i] = 'L';}
        else if (dominoes[left] == 'R' && dominoes[right] == 'R'){tmp[i] = 'R';}
        else if (dominoes[left] == 'R' && dominoes[right] == 'L'){
          if (i - left < right - i){tmp[i] = 'R';}
          else if (i - left == right - i){tmp[i] = '.';}
          else {tmp[i] = 'L';}
        }
        else {tmp[i] = 'R';}
      }
    }
    return tmp;
  }
};
int main()
{
  Solution* sol;
  
  cout << sol ->pushDominoes("..L.R...LR..L..")<< endl;
}
