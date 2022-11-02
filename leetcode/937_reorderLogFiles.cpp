#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <tuple>

using namespace std;
void print(vector<string> x){
  for (auto row: x){
    cout << row <<", ";
  }
  cout << endl;
}

class Solution {
public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> digitLogs;
    map<string, vector<string>> dataLogs;
    for (auto chara: logs){
      if (isdigit(chara[chara.size() - 1])){
        digitLogs.push_back(chara);
      }
      else {
        int idx = chara.find(' ');
        string identifiers = chara.substr(0, idx);
        string contents = chara.substr(idx + 1);
        dataLogs[contents].push_back(identifiers);
      }
    }
    logs.clear();
    for (auto it=dataLogs.begin(); it != dataLogs.end(); it++){
      sort(it -> second.begin(), it -> second.end());
      for (string iden: it -> second){
        logs.push_back(iden +" " + it -> first);
      }
    }
    logs.insert(logs.end(), digitLogs.begin(), digitLogs.end());
    return logs;
  }
};

int main()
{ 
  
  Solution* sol = new Solution();
  vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
  vector<string> out;
  out = sol -> reorderLogFiles(logs);
  print(out);
  return 0;
}