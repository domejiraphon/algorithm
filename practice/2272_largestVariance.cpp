/* 2272. Substring With Largest Variance
The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.
*/


class Solution {
public:
  int largestVariance(string s) {
    int largest=0;
    unordered_set<char> unique={s.begin(), s.end()};
    for (auto p: unique){
      for (auto q: unique){
        if (p == q)
          continue;
        int freq[2];
        memset(freq, 0, sizeof(freq));
        bool startWithQ=false;
        for (auto ch: s){
          if (ch == p)
            freq[0]++;
          else if (ch == q)
            freq[1]++;
          
          if (freq[1] > 0){
            largest = max(largest, freq[0] - freq[1]);
            startWithQ = false;
          }
          else if (freq[1] == 0 && startWithQ)
            largest = max(largest, freq[0] - 1);
          
          if (freq[1] > freq[0]){
            memset(freq, 0, sizeof(freq));
            startWithQ = true;
          }
        }
      }
    }
    return largest;
  }
};


class Solution {
public:
  int largestVariance(string s) {
    int ans=0;
    unordered_set<char> unique={s.begin(), s.end()};
    for (auto p: unique){
      for (auto q: unique){
        if (p == q)
          continue;
        int var=0; 
        bool hasQ=false;
        bool startWithQ = false;
        for (auto ch: s){
          var += (ch == p);
          if (ch == q){
            hasQ = true;
            
            if (startWithQ && var >= 0)
              startWithQ = false; 
            else if (--var < 0){
              var = -1; startWithQ = true; 
            }
    
          }
        
          ans = max(ans, (hasQ) ? var : 0);
          //cout << ans<< endl;
        }
        
      }
    }
    return ans;
  }
};
