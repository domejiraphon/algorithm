#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int firstBadVersion(int n) {
    return helper(1, n);
  }
private:
  int helper(int start, int end){
    if (end == start) {return isBadVersion(start) ? end : -1;}
    if (end - start == 1 &&
        isBadVersion(start) ==  false &&
        isBadVersion(end) == true){
          return end;
        }
    int idx = (int) (start + end)/2;
    bool mid = isBadVersion(idx);
    if (mid == true){
      return helper(start, idx);
    }
    else {
      return helper(idx, end);
    }
  }
  bool isBadVersion(int version){};
};

int main()
{ 
  
  Solution sol;
  vector<int> prices={7,1,5,3,6,4};
  cout << sol.maxProfit(prices)<< endl;

  return 0;
}