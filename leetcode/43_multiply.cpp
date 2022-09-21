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

class Solution {
public:
    string multiply(string num1, string num2) {
      map<char, int> hashTable;
      hashTable['0'] = 0; hashTable['1'] = 1; hashTable['2'] = 2;
      hashTable['3'] = 3; hashTable['4'] = 4; hashTable['5'] = 5;
      hashTable['6'] = 6; hashTable['7'] = 7; hashTable['8'] = 8; hashTable['9'] = 9;
      string out;
      int idxNum1(num1.size() - 1), idxNum2(num2.size() - 1), digit(0);
      int carry(0);
      while (idxNum2 >= 0){
        while (idxNum1 >= 0){
          int cur = hashTable[num1[idxNum1]] * hashTable[num2[idxNum2]];
          cur += carry;
          carry = (cur >= 10) ? 1: 0;
          cout << cur<< endl;
          out = to_string(cur %10) + out;
          idxNum1--; idxNum2--;
        }
        
      }
      if (idxNum1 > 0){
        out = num1.substr(0, idxNum1) + out;
      }
      if (idxNum2 > 0){
        out = num2.substr(0, idxNum2) + out;
      }
      return out;
    }

};

int main()
{ 
  
  Solution* sol;
  cout << sol ->multiply("123", "456")<<endl;
  exit(0);
  cout << sol ->multiply("123456789", "987654321")<<endl;
  cout << sol ->multiply("498828660196", "840477629533")<<endl;

  return 0;
}