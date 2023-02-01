/* 2398. Maximum Number of Robots Within Budget
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, both of length n. 
The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] units to run. 
You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts),
where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is 
the sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.
*/
class Compare {
public:
  bool operator () (pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
  }
};
class Solution {
public:
  int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    int n=chargeTimes.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> maxHeap;
    long long sum=0;
    int j=-1;
    int prev, ans(0);
    for (int i=0; i<n; i++){
      maxHeap.push({chargeTimes[i], i});
      sum += runningCosts[i];
      prev = maxHeap.top().first;
      
      while ((i -j) * sum + prev > budget){
        sum -= runningCosts[++j];
        
        while (!maxHeap.empty() && maxHeap.top().second <= j){
          maxHeap.pop();
        }
        prev = (!maxHeap.empty()) ? maxHeap.top().first : 0;
      }
      ans = max(ans, i - j);
      //cout << ans << endl;
    }
    return ans;
  }
};
