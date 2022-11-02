#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
  int minSwaps(string s) {
    if (!possible(s)){return -1;}
    int n = s.size();
   
    int mis0(0), mis1(0);

    for (int i=0; i < n; i+=2){
     mis0 += s[i] != '0';
     mis1 += s[i] != '1';
    }

    return min(mis0, mis1);
  }
private:
  bool possible(string& s){
    int count0(0), count1(0);
    for (auto ele: s){
      if (ele == '0'){count0++;}
      else {count1++;}
    }
    return (abs(count0 - count1) > 1) ? false : true;
  }
};

int main()
{ 
  
  Solution* sol = new Solution();
  cout << sol -> minSwaps("111000")<< endl;
  cout << sol -> minSwaps("010")<< endl;
  cout << sol -> minSwaps("1110")<< endl;
  return 0;
}