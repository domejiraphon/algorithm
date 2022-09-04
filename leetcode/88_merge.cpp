#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
template <typename T>
void print_vector(const std::vector<T> & vec, std::string sep=", ")
{
    for(auto elem : vec)
    {
        std::cout<<elem<< sep;
    }
    std::cout<<std::endl;
}

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector <int> nums3 = nums1;
    int idx_1(0);
    int idx_2(0);
    int i;
    for (i=0; i != m +n; i++){
      if (idx_1 > m || idx_2 > n){
        break;
      }
      if (nums1[idx_1] < nums2[idx_2]){
        nums3[i] = nums1[idx_1]; idx_1++;
      }
      else {
        nums3[i] = nums2[idx_2]; idx_2++;
      }
     
    }
    if (idx_1 < m){
      for (int idx = idx_1; idx != m; idx++){
        nums3[i-1] = nums1[idx];
        i++;
      }
    }
    else if (idx_2 < n){
      for (int idx = idx_2; idx != n; idx++){
        nums3[i-1] = nums2[idx];
        i++;
      }
    }
    nums1 = nums3;
  }
  
};

int main()
{ 
  vector <int> nums1 {1,2,3,0,0,0};
  vector <int> nums2 {2,5,6};
  Solution sol;
  sol.merge(nums1, 3, nums2, 3);
  print_vector(nums1);

  nums1 = {1}; nums2 = {};
  sol.merge(nums1, 1, nums2, 0);
  print_vector(nums1);

  nums1 = {0}; nums2 = {1};
  sol.merge(nums1, 0, nums2, 1);
  print_vector(nums1);
  return 0;
}