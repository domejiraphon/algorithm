
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int out=nums[0];
    for (int i=1; i != nums.size(); i++){
      out = out ^ nums[i];
    }
    return out;
  }
};

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++){
      freq[nums[i]]++;
    }
    for (auto it=freq.begin(); it != freq.end(); it++){
      if (it -> second == 1)
        return it -> first;
    }
    return -1;
  }
};