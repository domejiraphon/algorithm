class Solution {
public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    vector<string> name, cur;
    unordered_map<string, vector<tuple<int, int, string>>> timeCity;
    vector<int> time;
    int n=transactions.size();
    vector<bool> S(n, false);
    for (int i=0; i < n; i++){
      cur = split(transactions[i]);
      timeCity[cur[0]].push_back({i, stoi(cur[1]), cur[3]});
      name.push_back(cur[0]);
      if (stoi(cur[2]) > 1000){S[i] = true;}
    }
  
    for (auto it=timeCity.begin(); it != timeCity.end(); it++){
      vector<tuple<int, int, string>> cur = it -> second;
      n=cur.size();
      for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
          if (abs(get<1>(cur[i]) -get<1>(cur[j])) <= 60 && get<2>(cur[i]) != get<2>(cur[j])){
            S[i] = true; S[j] = true;
          }
        }
      }
    }
    n = transactions.size();
    name.clear();
    for (int i=0; i<n; i++){
      if (S[i]){
        name.push_back(transactions[i]);
      }
      
    }
    return name;
  }
private:
  vector<string> split(string transaction){
    size_t pos;
    vector<string> out;
    while ((pos = transaction.find(',')) != string::npos){
      string sub = transaction.substr(0, pos);
      out.push_back(sub);
      transaction.erase(0, pos+1);
    }
    out.push_back(transaction);
    return out;
  }
};

class Solution2 {
public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    vector<string> name;
    vector<string> cur;
    vector<string> city;
    vector<int> time;
    unordered_set<int> S;
    int n=transactions.size();
    for (int i=0; i < n; i++){
      cur = split(transactions[i]);
      name.push_back(cur[0]);
      city.push_back(cur[3]);
      time.push_back(stoi(cur[1]));
      if (stoi(cur[2]) > 1000){S.insert(i);}
    }
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        if (name[i] == name[j] && city[i] != city[j] && abs(time[i] - time[j]) <= 60){
          S.insert(i); S.insert(j);
        }
      }
    }
    name.clear();
    for (auto it=S.begin(); it != S.end(); it++){
      name.push_back(transactions[*it]);
    }
    return name;
  }
private:
  vector<string> split(string transaction){
    size_t pos;
    vector<string> out;
    while ((pos = transaction.find(',')) != string::npos){
      string sub = transaction.substr(0, pos);
      out.push_back(sub);
      transaction.erase(0, pos+1);
    }
    out.push_back(transaction);
    return out;
  }
};
