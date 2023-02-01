#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

class Solution {
public:
  int longestPalindrome(vector<string>& words) {
    int countDiff(0);
    unordered_map<string, int> hash;
    for (auto ele: words){
      string reverse = string(1, ele[1]) + string(1, ele[0]);
      if (hash.find(ele) != hash.end() && hash[ele] >0){
        countDiff += 4;
        hash[ele]--;
      }
      else{
        hash[reverse]++;
      }
    }
    for (auto it=hash.begin(); it != hash.end(); it++){
      string ele = it -> first;
      string reverse = string(1, ele[1]) + string(1, ele[0]);
      if (ele == (reverse) && it -> second > 0){
        countDiff += 2;
        break;
      }
    }
    return countDiff;
  }
};

int main()
{
  Solution* sol;
  vector<string> words;
  words = {"lc","lc","cl","gg"};
  cout << sol -> longestPalindrome(words) << endl;
  words = {"ab","ty","yt","lc","cl","ab"};
  cout << sol -> longestPalindrome(words) << endl;
  words = {"cc","ll","xx", "cc"};
  cout << sol -> longestPalindrome(words) << endl;

}
