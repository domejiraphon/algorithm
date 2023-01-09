class Solution {
public:
  int minMutation(string start, string end, vector<string>& bank) {
    queue<string> Q;
    Q.push(start);
    int num=0;
    unordered_set<string> bankDict = {bank.begin(), bank.end()};
    unordered_set<string> seen;
    while (!Q.empty()){
      int n=Q.size();
      for (int i=0; i<n; i++){
        string cur = Q.front();
        Q.pop();
        if (cur == end)
          return num;
        for (int j=0; j<10; j++){
          for (char ch: "ACGT"){
            string mut = cur;
            mut[j] = ch;
            if (bankDict.count(mut) && !seen.count(mut)){
              seen.insert(mut);
              Q.push(mut);
            }
          }
        }
      }
      num++;
    }
    return -1;
  }
};
