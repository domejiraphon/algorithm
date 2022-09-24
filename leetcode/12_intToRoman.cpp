#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto ele :row){
      cout << ele <<", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  string intToRoman(int num) {
    unordered_map<int, string> memo;
    vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    memo[val[0]] = "M"; memo[val[1]] = "CM";
    memo[val[2]] = "D"; memo[val[3]] = "CD";
    memo[val[4]] = "C"; memo[val[5]] = "XC";
    memo[val[6]] = "L"; memo[val[7]] = "XL"; 
    memo[val[8]] = "X"; memo[val[9]] = "IX"; 
    memo[val[12]] = "I"; memo[val[10]] = "V"; memo[val[11]] = "IV"; 

   
    string out;
    while (num){
      for (auto ele : val){
        if (num >= ele){
          num -= ele;
          out += memo[ele];
          break;
        }
      }

    }
    return out;
  }
};

int main()
{
  
  Solution* sol;
 
  cout << sol -> intToRoman(3)<<endl;
  cout << sol -> intToRoman(58)<<endl;
  cout << sol -> intToRoman(1994)<<endl;
  return 0;
}