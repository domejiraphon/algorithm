class Solution {
public:
  int numTeams(vector<int>& rating) {
    int n=rating.size();
    int res=0;
    
    for (int i=1; i< n  -1; i++){
      int less[2] = {}, great[2] = {};
      for (int j=0; j< n; j++){
        if (rating[i] < rating[j]){
          less[i < j]++;
        }
        if (rating[i] > rating[j]){
          great[i < j]++;
        }
      }
      
      res += less[0] * great[1] + less[1] * great[0];
    }
    return res;
  }
};
