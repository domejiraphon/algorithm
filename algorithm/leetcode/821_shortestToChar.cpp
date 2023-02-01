class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    s = c + s + c;
    int n=s.size();
    int pos=INT_MAX;
    vector<int> res;
    for (int i=0, j=1; j<n; j++){
      if (s[j] == c){
        cout << i << ", "<< j << endl;
        int num = j - i -1;
        if (i == 0){
          int k=num;
          while (k > 0){res.push_back(k--);}
        }
        else if (j == n - 1){
          int k=1;
          while (k <= num){res.push_back(k++);}
        }
        else {
          for (int rep=0; rep < num /2; rep++){
            res.push_back(rep + 1);
          }
          if (num % 2 == 1){res.push_back(num / 2 + 1);}
          for (int rep=num/2; rep > 0; rep--){
            res.push_back(rep);
          }
        }
        res.push_back(0);
        i = j;
      }
    }
    res.pop_back();
    return res;
  }
};
