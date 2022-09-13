#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

void print(vector<int> cur){
  for (auto it : cur){cout << it<<", ";}
  cout << endl;
}

void print(map<int, int> cur){
  for (auto it =cur.begin(); it != cur.end(); it++){cout << it -> first <<", "<< it -> second<<endl;}
  cout << endl;
}
class SparseVector {
private:
  map<int, int> hashTable;
public:
  SparseVector(vector<int> &nums) {
    for (int i=0; i != nums.size(); i++){
      if (nums[i] == 0){continue;}
      hashTable[i] = nums[i];
    }
  }
  
  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int out(0);
    for (auto it = hashTable.begin(); it != hashTable.end(); it++){
      if (vec.hashTable.find(it -> first) != vec.hashTable.end()){
        out += vec.hashTable[it -> first] * it -> second;
      }
    }
    return out;
  }
};

int main()
{
  vector<int> nums1 = {1,0,0,2,3};
  vector<int> nums2 = {0,3,0,4,0};
  SparseVector v1(nums1);
  SparseVector v2(nums2);

  int ans = v1.dotProduct(v2);
  cout << ans<<endl;

  nums1 = vector<int> {0,1,0,0,2,0,0};
  nums2 = vector<int> {1,0,0,0,3,0,4};
  SparseVector v3(nums1);
  SparseVector v4(nums2);

  cout << v3.dotProduct(v4)<<endl;
  return 0;
}