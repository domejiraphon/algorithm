class Solution {
public:
  int minimumKeypresses(string s) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for (auto ele: s){
      freq[ele - 'a']++;
    }
    sort(freq, freq + 26);
    
    int press(0);
    for (int i=25; i >= 0; i--){
      int x = 25 - i;
      press += freq[i] * ((x / 9) + 1);
    }
    return press;
  }
};

bool sortby(vector<int> a, vector<int> b){
  return a[0] > b[0];
}
class Solution2 {
public:
  int minimumKeypresses(string s) {
    vector<vector<int>> freq(26, vector<int>(2, 0));
    
    for (int i=0; i<26; i++){
      freq[i][1] = i;
    }
    for (auto ele: s){
      freq[ele - 'a'][0]++;
    }
    sort(freq.begin(), freq.end(), sortby);
    unordered_map<char, int> nums;
    for (int i=0; i<26; i++){
      if (i < 9){
        nums[freq[i][1] + 'a'] = 1;
      }
      else if (9<= i && i< 18){
        nums[freq[i][1] + 'a'] = 2;
      }
      else {
        nums[freq[i][1] + 'a'] = 3;
      }
    }
    int press(0);
    for (auto ch: s){
      press += nums[ch];
    }
    return press;
    
  }
};
