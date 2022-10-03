#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}

class Solution {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> memo(nums1.size() + 1, vector<int> (nums2.size() + 1, 0));
    int out(0);
    for (int i=0; i < nums1.size(); i++){
      for (int j=0;j < nums2.size(); j++){
        if (nums1[i] == nums2[j]){
          memo[i + 1][j + 1] = 1 + memo[i][j];
          out = max(out, memo[i + 1][j + 1]);
        }
      }
    }
    print(memo); 
    return out;
  }

};

int main()
{ 
  
  Solution* sol;
  vector<int> nums1 = {3,2,1};
  vector<int> nums2 = {3,2,1,4,7};

  cout << sol -> findLength(nums1, nums2)<< endl;

  nums1 = {0,0,0,0,0,0,1,0,0,0};
  nums2 = {0,0,0,0,0,0,0,1,0,0};

  cout << sol -> findLength(nums1, nums2)<< endl;
  return 0;
}