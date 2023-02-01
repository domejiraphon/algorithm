/* 
46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/
class Solution2 {
  vector<int> arr;
  vector<vector<int>> res;
  int n;
public:
  vector<vector<int>> permute(vector<int>& nums) {
    arr = nums;
    n = nums.size();
    unordered_set<int> used;
    vector<int> cur={};
    shuffle(used, cur);
    return res;
  }
private:
  void shuffle(unordered_set<int>& used, vector<int>& cur){
    if (used.size() == n){
      res.push_back(cur);
      return;
    }
    for (int i=0; i<n; i++){
      if (!used.count(i)){
        used.insert(i);
        cur.push_back(arr[i]);
        shuffle(used, cur);
        used.erase(i); cur.pop_back();
      }
        
    }

  }
};

class Solution {
  vector<int> arr;
  vector<vector<int>> res;
  int n;
public:
  vector<vector<int>> permute(vector<int>& nums) {
    arr = nums;
    n = nums.size();
    vector<int> cur={};
    shuffle(0, cur);
    return res;
  }
private:
  void shuffle(int i, vector<int> & cur){
    if (cur.size() == n){
      res.push_back(cur); return;
    }
    for (int j=i; j<n; j++){
      cur.push_back(arr[j]);
      swap(arr[i], arr[j]);
      shuffle(i + 1, cur);
      swap(arr[i], arr[j]);
      cur.pop_back();
    }
  }
};