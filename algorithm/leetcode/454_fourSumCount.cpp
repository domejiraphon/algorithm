#include <iostream>
#include <iterator>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void print(unordered_map<int, int>& hash){
  for (auto it=hash.begin(); it != hash.end(); it++){
    cout << it -> first <<": " << it -> second<< endl;
  }
}

class Solution {
public:
  int fourSumCount(vector<int>& nums1, 
    vector<int>& nums2, vector<int>& nums3, 
    vector<int>& nums4) {
    int n1 = nums1.size(), n2 = nums2.size();
    int n3 = nums3.size(), n4 = nums4.size();
    unordered_map<int, int> hash1 = getHash(nums1, nums2);
    unordered_map<int, int> hash2 = getHash(nums3, nums4);

    int count(0);
    for (auto it=hash1.begin(); it != hash1.end(); it++){
      if (hash2.count(- it -> first)){
        count += it -> second * hash2[- it -> first];
      }
    }
    return count;
  }
private:
  unordered_map<int, int> getHash(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> hash;
    for (auto i: nums1){
      for (auto j: nums2){
        hash[i + j]++;
      }
    }
    return hash;
  }
};

int main()
{
  Solution* sol;
  vector<int> nums1 = {1, 2}; 
  vector<int> nums2 = {-2,-1};
  vector<int> nums3 = {-1,2};
  vector<int> nums4 = {0,2};

  cout << sol -> fourSumCount(nums1, nums2, nums3, nums4)<< endl;
  return 0;
}