class Solution {
public:
  vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> hash;
    vector<string> res;
    for (auto name: names){
      string cur = name; 
      while (hash.count(cur)){
        cur = name + "(" + to_string(hash[name]++) + ")";
      }
      hash[cur]++;
      res.push_back(cur);
    }
    return res;
  }
};
