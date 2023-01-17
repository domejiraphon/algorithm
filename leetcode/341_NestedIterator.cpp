/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
  deque<NestedInteger> Q;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    for (auto NestedInt: nestedList)
      Q.push_back(NestedInt);
    
  }
  
  void makeStackTopInteger(){
    while (!Q.empty() && !Q.front().isInteger()){
      vector<NestedInteger> cur = Q.front().getList();
      Q.pop_front();
      for (int i = cur.size() - 1; i>=0; i--)
        Q.push_front(cur[i]);
    }
  }
  int next() {
    int tmp = Q.front().getInteger();
    Q.pop_front();
    return tmp;
  }
  
  bool hasNext() {
    makeStackTopInteger();
    return !Q.empty();
  }
};

class NestedIterator {
  vector<int> flatten;
  int size;
  int i;
public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    helper(nestedList);
    i = 0;
    size = flatten.size();
  }

  void helper(vector<NestedInteger> &nestedList){
    for (auto ele: nestedList){
      if (ele.isInteger())
        flatten.push_back(ele.getInteger());
      else {
        vector<NestedInteger> cur = ele.getList();
        helper(cur);
      }
    }
  }

  int next() {
    return flatten[i++];
  }
  
  bool hasNext() {
    return (i < size);
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */