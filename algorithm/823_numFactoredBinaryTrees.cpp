/*
823. Binary Trees With Factors

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. 
Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.
*/
class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    int n=arr.size();
    sort(arr.begin(), arr.end());
    unordered_map<int, long> hash;
    
    int mod = pow(10, 9) + 7;
    long sum=0;
    for (int i=0; i<n; i++){
      hash[arr[i]] = 1;
      for (int j=0; j<i; j++){
        if (arr[i] % arr[j] == 0){
          int comp = arr[i] / arr[j];
          if (hash.count(comp)){
            long cur = hash[comp] * hash[arr[j]] % mod;
            hash[arr[i]] += cur;
          }
        }
      }
      sum += hash[arr[i]];
    }
    return sum % mod;
  }
};