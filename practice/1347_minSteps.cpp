class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> freq(26);
    int n=s.size();
    for (int i=0 ; i<n; i++){
      freq[s[i] - 'a']++;
      freq[t[i] - 'a']--;
    }
   
    int count(0);
    for (auto ele: freq){
      if (ele > 0){count += ele;}
    }
    return count;
  }
};
