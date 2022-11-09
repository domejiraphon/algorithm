#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
private:
  vector<int> cumulative;
public:
  Solution(vector<int>& w) {
    int sum(0);
    for (auto ele: w){
      sum += ele;
      cumulative.push_back(sum);
      }
  }

  int pickIndex() {
    float val = (float) rand() / RAND_MAX * cumulative.back();
    int idx = lower_bound(cumulative.begin(), cumulative.end(), val) - cumulative.begin();
    return idx;
  }
};


int main()
{
  vector<int> w ={1, 3};
  Solution* obj = new Solution(w);
  int param_1 = obj->pickIndex();
  return 0;
}