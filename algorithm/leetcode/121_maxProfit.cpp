/*
121. Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int maxP=0;
    int minB=prices[0];
    for (int i=0; i<n; i++){
      minB = min(minB, prices[i]);
      maxP = max(maxP, prices[i] - minB);
    }
    return maxP;
  }
};