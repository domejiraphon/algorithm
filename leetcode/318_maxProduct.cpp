class Solution {
public:
  int maxProduct(vector<string>& words) {
    unordered_map<int, int> bitHash;
    int n=words.size();
    for (int i=0; i< n; i++){
      int cur = getBitMask(words[i]);
      if (bitHash.count(cur)){
        bitHash[cur] = (bitHash[cur] < words[i].size()) ? words[i].size() : bitHash[cur];
      }
      else {
        bitHash[cur] = words[i].size();
      }
    }
    int maxProd;
    for (auto it1 = bitHash.begin(); it1 !=bitHash.end(); it1++){
      for (auto it2 = bitHash.begin(); it2 !=bitHash.end(); it2++){
        if (it1 == it2){continue;}
        if ((it1 -> first & it2 -> first) == 0){
          maxProd = max(maxProd, it1 -> second * it2 -> second);
        }
      }
    }
    return maxProd;
  }
private:
  int bitNumber(char ch){
    return (int) ch - 'a';
  }
  int getBitMask(string word1){
    int bitmask1=0;
    for (auto ch: word1){
      bitmask1 |= 1 << bitNumber(ch);
    }
    return bitmask1;
  }
};
