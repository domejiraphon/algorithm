class Solution {
public:
  int mergeStones(vector<int>& stones, int k) {
    int n=stones.size();
    if ((n -1) %(k - 1) != 0)
      return -1;
    vector<int> prev=stones;
    vector<int> next;
    int cost=0;
    while (prev.size() > 1){
      int minSum=INT_MAX;
      int curSum=0;
      for (int i=0; i<prev.size(); i++){
        curSum += prev[i];
        if (i >= k)
          curSum -= prev[i-k];
        if (i >= k-1){
          
          if (curSum < minSum){
            minSum = curSum;
            next = {};
            next.insert(next.end(), prev.begin(), prev.begin() + i-k+1);
            next.push_back(curSum);
            
            next.insert(next.end(), prev.begin() + i+1, prev.end());
            
          }
        }
      }
      print(next); 
      prev = next;
      cost += minSum;
    }
    return cost;
    
  }
private:
  void print(vector<int>& arr){
    for (auto a: arr){
      cout << a <<", ";
    }
    cout << endl;
  }
};
