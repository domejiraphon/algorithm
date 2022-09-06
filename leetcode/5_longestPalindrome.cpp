#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string out="";
    for (int i=0; i != s.size(); i++)
    {
      for (int j=0; j != s.size(); j++)
      {
        string cur = s.substr(i, s.size() - j);
        while (cur != "")
        {
          if (cur[0] != cur[cur.size()-1]){ break;}
          else 
          {
            cur=cur.substr(1, cur.size()-2);
          }
          
        }
        if (cur == "")
        {
          out = (s.substr(i, s.size() - j).size() > out.size()) ? s.substr(i, s.size() - j) : out;
        }
      }
    }
    return out;
  }
};

int main()
{ 
  string s;
  Solution sol;
  s = "babab";
  cout<< sol.longestPalindrome(s) << endl;
  s="cbbd";
  cout<< sol.longestPalindrome(s) << endl;
  s="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
  cout<< sol.longestPalindrome(s) << endl;
  return 0;
}