#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > 6 * nums2.size() || nums2.size() > 6 * nums1.size()){
      return -1;
    }
    int sum1 = sum(nums1);
    int sum2 = sum(nums2);
    if (sum1 > sum2){return minOperations(nums2, nums1);}
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int left(0), right(nums2.size() - 1);
    int count(0);
    while (sum1 < sum2){
      count++;
      if (right < 0 || left < nums1.size() && 6 - nums1[left] > nums2[right] - 1){
        sum1 += 6 - nums1[left++];
      }
      else {
        sum2 -= nums2[right--] - 1;
      }
    }
    return count;
  }
private:
  int sum(vector<int>& nums){
    int out(0);
    for (auto ele: nums){out += ele;}
    return out;
  }
};

int main()
{ 
  
  Solution* sol;
  
  vector<int> nums1 = {6, 6};
  vector<int> nums2 = {1};
  cout << sol -> minOperations(nums1, nums2) << endl;
  return 0;
}