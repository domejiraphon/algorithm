class Solution {
public:
  int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (auto n: nums)
      freq[n]++;
    int sum=0;
    for (auto f: freq)
      if (f.second == 1)
        sum += f.first;
      
    return sum;
  }
};
