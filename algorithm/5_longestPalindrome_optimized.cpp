#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string tmp="";
    for (int i=0; i != s.size(); i++)
    {
      string out = s.substr(i, 1);
      bool not_end=true;
      int it_left=1, it_right=1;
      while (not_end)
      {
        cout << out << endl;
        
      
        if (((i-it_left) > -1) && (it_right+1) < s.size())
        {
          if (out[0] != out[out.size()-1])
          {
            tmp = (out.size() > tmp.size()) ? out : tmp;
          }
          out = s.substr(i-it_left, it_right+1);
          if (it_left %2 == 0){it_left++; }
          else {it_right++;}
        }
        else
        {
          not_end=false;
        }
        
      }
      
    }
    return tmp;
  }
};

int main()
{ 
  string s;
  Solution sol;
  s = "babab";
  cout<< sol.longestPalindrome(s) << endl;
  s="cbbd";
  //cout<< sol.longestPalindrome(s) << endl;
  s="ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
  //cout<< sol.longestPalindrome(s) << endl;
  return 0;
}