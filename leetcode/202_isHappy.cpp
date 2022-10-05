#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <cmath>
#include <vector>
#include <list>

using namespace std;
class Solution {
public:
  bool isHappy(int n) {
    int out(0);
    unordered_set<int> repeat;
    repeat.insert(n);
    while (true){
      out = sumSquare(n);
      if (out == 1){
        return true;}
      else {
        if (repeat.find(out) != repeat.end()){return false;}
        else {repeat.insert(out);}
      }
      n = out;
    }
    
  }
private:
  int sumSquare(int n){
    int count(0);
    while (log10(n) >= 0){
      count += pow(n % 10, 2);
      n = (int) n / 10;
    }
    return count;
  }
};
int main()
{
  Solution* sol;
  cout << sol -> isHappy(19)<< endl;
  cout << sol -> isHappy(2)<< endl;
}
