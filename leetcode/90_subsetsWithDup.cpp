class Solution {
private:
  int n;
  vector<int> arr;
  vector<vector<int>> res;
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    arr = nums;
    n = nums.size();
    backtrack(0, vector<int> {});
    return res;
  }
private:
  void backtrack(int idx, vector<int> cur){
    res.push_back(cur);
    for (int i=idx; i<n; i++){
      if (i != idx && arr[i] == arr[i - 1]){continue;}
      cur.push_back(arr[i]);
      backtrack(i+1, cur);
      cur.pop_back();
    }
  }
};
