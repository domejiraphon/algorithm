#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
class Solution {
public:
  int maxProfit(vector<int>& prices) {
  int out(0);
  for (int i=0; i != prices.size() - 1; i++){
    if (prices[i] > prices[i+1]){continue;}
    out += prices[i+1] - prices[i];
  }
  return out;
  }
};
int main()
{ 
  
  Solution* sol;
  vector<int> prices={7,1,5,3,6,4};
  cout << sol -> maxProfit(prices)<< endl;

  return 0;
}