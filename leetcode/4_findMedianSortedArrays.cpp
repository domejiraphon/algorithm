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
    int n=nums1.size();
    int m=nums2.size();
    if (n > m){
      return findMedianSortedArrays(nums2, nums1);
    }
    int low = 0, high = n - 1;
    while (low < high){
      int med1 = (high + low) / 2;
      int med2 = (n + m + 1)/2 - med1;

      int l1 = (med1 > 0) ? nums1[med1 - 1] : -INT_MAX;
      int l2 = (med2 > 0) ? nums2[med2 - 1] : -INT_MAX;

      int r1 = nums1[med1];
      int r2 = nums2[med2];
      cout << l1 << ", "<< l2 << ", "<< r1<<", "<< r2 << endl;
      exit(0);
      if (l1 <= r2 && l2 <= r1){
        return (n + m %2 == 0) ? ();
      }
      else if (l1 > r2){
        high = med1 - 1;
      }
      else if (l2 > r1){
        low = med1 + 1;
      }
    }
  }
};

int main()
{ 
  
  Solution* sol;

  vector<int> nums1 = {1,3};
  vector<int> nums2 = {2};
  //cout << sol ->findMedianSortedArrays(nums1, nums2)<<endl;

  nums1 = vector<int> {1, 2, 9};
  nums2 = vector<int> {3, 4, 5, 6, 7};
  cout << sol ->findMedianSortedArrays(nums1, nums2)<<endl;

  return 0;
}