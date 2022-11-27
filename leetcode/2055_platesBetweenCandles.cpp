class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    vector<int> pos;
    int n=s.size();
    for (int i=0; i< n; i++){
      if (s[i] == '|'){pos.push_back(i);}
    }
    vector<int> res;
    for (auto q: queries){
      int left = lower_bound(pos.begin(), pos.end(), q[0]) - pos.begin();
      int right = upper_bound(pos.begin(), pos.end(), q[1]) - pos.begin() - 1;
      res.push_back(left < right ? pos[right] - pos[left] - (right - left): 0);
    }
    return res;
  }
};
