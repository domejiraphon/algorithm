/* 1570. Dot Product of Two Sparse Vectors
Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?
*/
class SparseVector {
  map<int, int> idx;
public:
  SparseVector(vector<int> &nums) {
    int n=nums.size();
    for (int i=0; i<n; i++){
      if (nums[i] != 0)
        idx[i] = nums[i];
    }
  }
  
  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    map<int, int> idx2 = vec.idx;
    int sum=0;
    for (auto it=idx.begin(); it != idx.end(); it++){
      if (idx2.count(it -> first))
        sum += idx2[it -> first] * it -> second;
    }
    return sum;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);