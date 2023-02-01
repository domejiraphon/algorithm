/* 2055. Plates Between Candles

There is a long table with a line of plates and candles arranged on top of it. 
You are given a 0-indexed string s consisting of characters '*' and '|' only, 
where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] 
denotes the substring s[lefti...righti] (inclusive). For each query, 
you need to find the number of plates between candles that are in the substring. 
A plate is considered between candles if there is at least one candle to its left and 
at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". 
The number of plates between candles in this substring is 2, as each of the two plates 
has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.


*/
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
