#include <iostream>
#include <iterator>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }
    string out;
    if (numerator < 0 ^ denominator < 0){
      out += "-";
    }
    long top = (long) abs(numerator);
    long bottom = (long) abs(denominator);
    
    out += to_string(top / bottom);
    long leftOver = top % bottom;
    unordered_map<long, int> Map;
    if (leftOver == 0){
      return out;}

    out += ".";
    
    while (leftOver != 0){
      if (Map.find(leftOver) != Map.end()){
        out.insert(Map[leftOver], "(");
        out += ")";
        break;
      }
      Map[leftOver] = out.size();
      leftOver *= 10;
      out += to_string(leftOver / bottom);
      leftOver %= denominator;
    }
    return out;
  }
};

int main()
{ 
  Solution* sol;
  //cout << sol ->fractionToDecimal(1, 2)<< endl;
  cout << sol ->fractionToDecimal(7, -12)<< endl;
  //cout << sol ->fractionToDecimal(4, 333)<< endl;

  return 0;
}