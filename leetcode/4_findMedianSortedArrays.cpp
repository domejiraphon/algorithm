#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<int> x){
  
    for (auto elem: x){
      cout << elem <<", ";}
  cout << endl;
  
}

int getDigit(int n, int idx=0)
{
  int digits = (int)log10(n);
  n = (int)(n / pow(10, digits -idx));
  if (idx !=0){
    return n% 10;
  }
  return n;
}

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
  }
};

int main()
{ 
  
  Solution* sol;

  vector<int> nums1 = {1,3};
  vector<int> nums2 = {2};
  cout << sol ->findMedianSortedArrays(nums1, nums2)<<endl;

  nums1 = vector<int> {1, 2};
  nums2 = vector<int> {3, 4};
  cout << sol ->findMedianSortedArrays(nums1, nums2)<<endl;

  return 0;
}