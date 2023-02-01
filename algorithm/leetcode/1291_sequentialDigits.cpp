class Solution {
private:
  string limit = "123456789";
public:
  vector<int> sequentialDigits(int low, int high) {
    int minWindow = log10(low);
    int maxWindow = log10(high);
    vector<int> res;
    for (int i=minWindow; i <= maxWindow; i++){
      for (int j=0; j < 9 - i; j++){
        int cur = stoi(limit.substr(j, i+1));
        if (cur >=low && cur <= high){
          res.push_back(cur);
        }
        if (cur > high){return res;}
      }
    }
    return res;
  }
};
