class Solution {
private:
  vector<int> res;
  int K, N;
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    N = n; K = k;
    diff(0, 0);
    return res;
  }
private:
  void diff(int idx, int prev){
    if (idx == N){res.push_back(prev); return;}
    int prevLast = prev % 10;
    int start = (idx == 0) ? 1 : 0;
    for (int i=start; i<=9; i++){
      if (idx == 0){
        diff(idx + 1, 10*prev + i);
      }
      else if (abs(i - prevLast) == K){
        diff(idx + 1, 10*prev + i);
      }
    }
  }
};
