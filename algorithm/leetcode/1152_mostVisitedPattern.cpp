/*
1152. Analyze User Website Visit Pattern
You are given two string arrays username and website and an integer array timestamp. All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

A pattern is a list of three websites (not necessarily distinct).

For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.
The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.

For example, if the pattern is ["home", "away", "love"], the score is the number of users x such that x visited "home" then visited "away" and visited "love" after that.
Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users x such that x visited "luffy" three different times at different timestamps.
Return the pattern with the largest score. If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.

*/
class Solution {
public:
  vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    unordered_map<string, map<int, string>> users;
    int n=username.size();
    for (int i=0; i<n; i++)
      users[username[i]][timestamp[i]] = website[i];

    unordered_map<string, int> pattern;
    for (auto it=users.begin(); it != users.end(); it++){
      map<int, string> cur = it -> second;
      unordered_set<string> ts;
      for (auto it1 = cur.begin(); it1 != cur.end(); it1++){
        for (auto it2 = next(it1); it2 != cur.end(); it2++){
          for (auto it3 = next(it2); it3 != cur.end(); it3++){
            ts.insert(it1 -> second +'/'+ it2 -> second +'&'+ it3 -> second);
          }
        }
      }
      for (auto t: ts)
        pattern[t]++;
    }
    string maxPattern="";
    int score=0;
    for (auto it=pattern.begin(); it != pattern.end(); it++){
      if (score <= it -> second){
        maxPattern = score < it -> second ? it -> first : min(maxPattern, it -> first);
        score = it -> second;
      }
    }
    
    int p1 = maxPattern.find("/");
    int p2 = maxPattern.find("&");
    return {maxPattern.substr(0, p1), maxPattern.substr(p1+1, p2 - p1 - 1), maxPattern.substr(p2+1)};
  }
};