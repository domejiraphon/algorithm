#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
void print(vector<T> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
      sort(matchsticks.begin(), matchsticks.end());
      vector<int> tmp(matchsticks);
      return backtracking(tmp);
    }
private:
    bool backtracking(vector<int> tmp){
      if (tmp.size() < 4){return false;}
      if (tmp.size() == 4){
        if (tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3]){return true;} 
        else {return false;}
      }
      for (int i=0; i != tmp.size(); i++){
        for (int j=0; j != tmp.size()-1; j++){
          vector<int> cur = {tmp.begin(), tmp.begin()+i};
          vector<int> sec = {tmp.begin()+i+1, tmp.end()};
          cur.insert(cur.end(), sec.begin(), sec.end());
          cur[j] += tmp[i];
          if (backtracking(cur)){return true;}
        }
        
      }
      return false;

    }
};

int main()
{
  
  Solution sol;
  vector<int> matchsticks={1,1,2,2,2};
  
  cout << sol.makesquare(matchsticks)<<endl;

  matchsticks = vector<int> {3, 3, 3, 3, 4};
  cout << sol.makesquare(matchsticks)<<endl;

  matchsticks = vector<int> {3, 3, 3, 1, 2};
  cout << sol.makesquare(matchsticks)<<endl;

  return 0;
}