#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void print(map<int, bool> x){
  for (auto it = x.begin(); it != x.end(); it++) {
    cout << it -> first <<", " << it -> second<<endl;
  }
}

class Solution {
public:
  int longestConsecutive(vector<int> nums) {
    if (nums.size()==0){return 0;}
    set<int> S={nums.begin(), nums.end()};
    nums.clear();
    nums = vector<int> (S.begin(), S.end() );
    int count(1);
    int out(1);
    for (int i=0; i != nums.size()-1; i++){
      if (nums[i+1] - nums[i] == 1){count++; out=max(out, count);}
      else{count=1;}
    }
    return out;
  }
};

int main()
{
  vector<int> nums={100,4,200,1,3,2};
  //vector<int> nums={1,2};
  Solution sol;
  
  cout << sol.longestConsecutive(nums) << endl;

  return 0;
}