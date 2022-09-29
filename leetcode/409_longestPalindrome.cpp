#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (auto ele: s){
      map[ele]++;
    }
    int counter(0);
    for (auto it=map.begin(); it != map.end(); it++){
      counter += ((int)it -> second / 2) * 2;
      if (counter % 2==0 && it -> second %2 == 1){
        counter++;
      }
    }
    return counter;
  }
};

int main()
{ 
 
  Solution* sol;
  cout << sol -> longestPalindrome("bananas") << endl;
  cout << sol -> longestPalindrome("abccccdd") << endl;
  cout << sol -> longestPalindrome("abcccdd") << endl;
  cout << sol -> longestPalindrome("a") << endl;

  return 0;
}