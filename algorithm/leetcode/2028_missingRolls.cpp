#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m=rolls.size();
    int sum(0);
    for (auto ele: rolls){
      sum += ele;
    }
    sum = mean *(n+m) - sum;
    if (sum > 6*n || sum < n){return vector<int> {};}
    
    vector<int> res(n, (int) sum / n);
    for (int i = 0; i < sum % n; ++i) 
      ++res[i];
    return res;
  }
};