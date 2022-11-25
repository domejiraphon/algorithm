class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int cur=prices[0], curP;
    int maxPro=0;
    int n=prices.size();
    for (int i=1; i<n; i++){
      curP = prices[i] - cur;
      if (curP < 0){cur = prices[i];}
      maxPro = max(maxPro, curP);
    }
    return maxPro;
  }
};