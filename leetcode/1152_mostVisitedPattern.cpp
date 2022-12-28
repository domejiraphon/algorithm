/*
1152. Analyze User Website Visit Pattern
*/
struct user {
  string username;
  string website;
  int time;
  user (string a, string b, int t){username = a; website = b; time = t;}
};
bool Cmp(user* &a, user* &b){return a -> time < b ->time;}

class Solution {
public:
  vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    vector<user*> users;
    int n=username.size();
    for (int i=0; i<n; i++){
      users.push_back(new user(username[i], 
                              website[i],
                              timestamp[i]));
    }
    sort(users.begin(), users.end(), Cmp);
    for (int i=0; i<n; i++){
      username[i] = users[i] -> username;
      website[i] = users[i] -> website;
      timestamp[i] = users[i] -> time;
    }
    map<string, int> invertedIndex;
    string pattern;
    for (int i=0; i<n; i++){
      for (int j=i+1; j<n; j++){
        for (int k=j+1; k<n; k++){
          if (users[i] == users[j] && users[j] == users[k]){
            pattern = website[i]+","+website[j] +","+ website[k];
            invertedIndex[pattern]++;
          }
        }
      }
    }
    map<int, vector<string>> index;
    for (auto it=invertedIndex.begin(); it != invertedIndex.end(); it++){
      index[it -> second].push_back(it -> first);
    }
    vector<string> out=index.end() -> second;
    sort(out.begin(), out.end());
    cout << out[0]<< endl;
    return out;
  }
};
