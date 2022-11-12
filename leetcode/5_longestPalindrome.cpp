#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;
void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
}
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    string longest=s.substr(0, 1);
    for (int i=0; i < n; i++){
      dp[i][i] = true;
      if (i+1< n){
        dp[i][i+1] = (s[i] == s[i+1]) ? true : false;
        if (dp[i][i+1]){longest = s.substr(i, 2);}
      }
    }
    
    for (int i=n - 2; i >=0; i--){
      for (int j=i+1; j < n; j++){
        if (s[i] == s[j] && dp[i+1][j-1]){
          dp[i][j] = true;
          if (longest.size() < j - i + 1){
            longest = s.substr(i, j - i+1);
          }
        }
      }
    }
    return longest;
  }

};

int main()
{ 
  string s;
  Solution sol;
  s = "aacabdkacaa";
  cout<< sol.longestPalindrome(s) << endl;
  s="cbbd";
  cout<< sol.longestPalindrome(s) << endl;
  s="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
  cout<< sol.longestPalindrome(s) << endl;
  return 0;
}