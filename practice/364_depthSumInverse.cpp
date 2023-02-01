/*
You are given a nested list of integers nestedList. Each element is either an integer or a list whose elements may also be integers or other lists.

The depth of an integer is the number of lists that it is inside of. For example, the nested list [1,[2,2],[[3],2],1] has each integer's value set to its depth. Let maxDepth be the maximum depth of any integer.

The weight of an integer is maxDepth - (the depth of the integer) + 1.

Return the sum of each integer in nestedList multiplied by its weight.


*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    unordered_map<int, int> depth;
    int maxDepth = maxD(nestedList, 1, depth);
    int sum=0;
    for (auto it=depth.begin(); it!=depth.end(); it++){
      sum += (maxDepth - it -> first + 1) * it -> second;
    }
    return sum;
  }
private:
  int maxD(vector<NestedInteger>& nestedList, int cur, unordered_map<int, int>& depth){
    if (nestedList.size() == 0)
      return INT_MIN;
    int out=1;
    int sum=0;
    for (auto nested: nestedList){
      if (!nested.isInteger())
        out = max(out, 1 + maxD(nested.getList(), cur+1, depth));
      else
        sum += nested.getInteger();
    }
    depth[cur] += sum;
    return out;
  }
};