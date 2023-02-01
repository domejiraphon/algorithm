#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

void print(vector<char> x){
  for (auto row: x){
      cout << row<<", ";
    
  }
  cout << endl;
}
void print(vector<tuple<char, int>> x){
  for (auto row: x){
      cout << get<0>(row)<<", "<< get<1>(row)<<endl;
  }
  cout << endl;
}

class Solution {
public:
  int compress(vector<char>& chars) {
    vector<tuple<char, int>> memo;
    int start(0), end(0), count(0);
    char prev_chars;
    while (end < chars.size()){
      if (chars[start] == chars[end]){
        count++; end++;
      }
      else{
        tuple<char, int> prev = {prev_chars, count};
        memo.push_back(prev);
        start=end;
        count=0;
      }
      prev_chars = chars[start];
    }
    tuple<char, int> prev = {prev_chars, count};
    memo.push_back(prev);
    
    
    count = 0;
    chars.clear();
    for (auto it=0; it != memo.size(); it++){
      count++;
      chars.push_back(get<0>(memo[it]));
      if (get<1>(memo[it]) == 1){continue;}
      string cur = to_string(get<1>(memo[it]));
      count += cur.size();
      
      for(int i=0; i != cur.size(); i++){chars.push_back(cur[i]);}
    }
    return count;
 
  }
};

int main()
{
  vector<char> chars = {'a'};
  
  Solution sol;
  cout << sol.compress(chars)<<endl;
  print(chars);
  return 0;
}