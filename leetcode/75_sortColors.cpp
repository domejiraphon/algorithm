#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <vector>
#include <list>

using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

class Solution2 {
public:
  void sortColors(vector<int>& nums) {
    nums = mergeSort(nums);
  }
private:
  vector<int> mergeSort(vector<int>& nums){
    if (nums.size() < 2){return nums;}
    int idx = (int) nums.size() / 2;
    vector<int> leftA = {nums.begin(), nums.begin() + idx};
   
    vector<int> left = mergeSort(leftA);

    vector<int> rightA = {nums.begin() + idx, nums.end()};
    vector<int> right = mergeSort(rightA);
    
    vector<int> out = merge(left, right);
    return out;
  }
  vector<int> merge(vector<int>& left, vector<int>& right){
    int n = left.size();
    int m = right.size();
    int i(0), j(0);
    vector<int> out;
   
    while (i < n && j < m){
      if (left[i] < right[j]){
        out.push_back(left[i]);
        i++;
      }
      else {
        out.push_back(right[j]);
        j++;
      }
    }
    
    if (i != n){out.insert(out.end(), left.begin() + i, left.end());}
    if (j != m){out.insert(out.end(), right.begin() + j, right.end());}
    
    return out;

  }
};

class Solution3 {
public:
  void sortColors(vector<int>& nums) {
    int leftIdx(0);
    int n(nums.size()), rightIdx(n);
    for (int i=0; i < n; i++){
      if (nums[i] == 0){
        swap(nums[i], nums[leftIdx++]);
      }
    }
    
    for (int i=leftIdx; i < n; i++){
      if (nums[i] == 1){
        swap(nums[i], nums[leftIdx++]);
      }
    } 
  }
};

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int leftIdx(0);
    int rightIdx(nums.size() - 1), i(0);
    while (i <= rightIdx){
      if (nums[i] == 0){
        swap(nums[i++], nums[leftIdx++]);
      }
      else if (nums[i] == 2){
        swap(nums[i], nums[rightIdx--]);
      }
      else {i++;}
     
    }
    
  }
};

int main()
{
  Solution* sol;
  vector<int> nums = {2, 0, 1};
  sol -> sortColors(nums);
  print(nums);
}
