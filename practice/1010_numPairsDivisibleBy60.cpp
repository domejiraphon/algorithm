class Solution {
public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int remainder[60];
    memset(remainder, 0, sizeof(remainder));
    int count(0);
    for (auto t: time){
      if (t % 60 == 0){
        count += remainder[0];
      }
      else {
        count += remainder[60 - (t % 60)];
      }
      remainder[t % 60]++;
    }
    return count;
  }
};
