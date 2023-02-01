class Solution {
private:
  unordered_map<string, int> hash;
public:
  int minDistance(string word1, string word2){
    if (word1 == ""){return word2.size();}
    if (word2 == ""){return word1.size();}
    string key = word1 + "_" + word2;
    if (hash.count(key)){return hash[key];}
    int ans=INT_MAX;
    if (word1[0] != word2[0]){
      ans = min(minDistance(word1.substr(1), word2.substr(1)),
               minDistance(word1.substr(1), word2));
      ans = min(ans, 
               minDistance(word1, word2.substr(1)));
      ans++;
    }
    else {
      ans = minDistance(word1.substr(1), word2.substr(1));
    }
    return hash[key] = ans;
  }
};
