/*
1169. Invalid Transactions
A transaction is possibly invalid if:

the amount exceeds $1000, or;
if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

Return a list of transactions that are possibly invalid. You may return the answer in any order.
*/
class Solution {
public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    unordered_map<string, vector<tuple<int, int, string>>> trans;
    int n=transactions.size();
    vector<bool> invalid(n, false);
    for (int i=0; i<n; i++){
      vector<string> out = split(transactions[i]);
      int amount = stoi(out[2]);
      
      trans[out[0]].push_back({i, stoi(out[1]), out[3]});
      if (amount > 1000)
        invalid[i] = true;
    }
    for (auto it=trans.begin(); it != trans.end(); it++){
      vector<tuple<int, int, string>> cur = it -> second;
      int m=cur.size();
      
      for (int i=0; i<m; i++){
        for (int j=i+1; j<m; j++){
          if (abs(get<1>(cur[i]) -get<1>(cur[j])) <= 60 && get<2>(cur[i]) != get<2>(cur[j])){
            invalid[get<0>(cur[i])] = true;
            invalid[get<0>(cur[j])] = true;
            //invalid[i] = true;
            //invalid[j] = true;
          }
        }
      }
    }
    vector<string> out;
    for (int i=0; i<n; i++){
      if (invalid[i])
        out.push_back(transactions[i]);
    }
    return out;
  }
private:
  vector<string> split(string& transaction){
    vector<string> out;
    int n=transaction.size();
    string cur="";
    for (int i=0; i<=n; i++){
      if (i==n || transaction[i] == ','){
        out.push_back(cur);
        cur = "";
      }
      else
        cur += transaction[i];
    }
    return out;
  }
};