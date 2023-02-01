/* 528. Random Pick with Weight
You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).

*/
class Solution {
  vector<int> sum;
  int n;
public:
  Solution(vector<int>& w) {
    n=w.size();
    sum.resize(n, w[0]);
    for (int i=1; i<n; i++)
      sum[i] = sum[i - 1] + w[i];
  }
  
  int pickIndex() {
    //int num = rand() % sum[n - 1];
    float num = (float) rand() / RAND_MAX * sum.back();
    int idx = lower_bound(sum.begin(), sum.end(), num) - sum.begin();
    return idx;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */