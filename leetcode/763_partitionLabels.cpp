class Solution {
public:
  vector<int> partitionLabels(string s) {
    int idx[26][2];
    memset(idx, -1, sizeof(idx));
    int n =s.size();
    for (int i=0; i< n; i++){
      if (idx[s[i] - 'a'][0] == -1){
        idx[s[i] - 'a'][0] = i;
      }
      idx[s[i] - 'a'][1] = i;
    }
    vector<pair<int,int>> interval;
    for (int i=0; i<26; i++){
      if (idx[i][0] != -1){
        interval.push_back({idx[i][0], idx[i][1]});
      }
    }
    sort(interval.begin(), interval.end());
    int start = interval[0].first, end = interval[0].second;
    vector<int> res;
    for (int i =1; i< interval.size(); i++){
      pair<int, int> cur = interval[i];
      if (cur.first >= start && cur.first < end){
        end = max(end, cur.second);
      }
      else {
        res.push_back(end -start + 1);
        start = cur.first;
        end = cur.second;
      }
    }
    res.push_back(end -start + 1);
    return res;
  }
};
