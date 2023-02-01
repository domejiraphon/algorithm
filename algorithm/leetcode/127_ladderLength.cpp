/*
127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> Q;
    Q.push(beginWord);
    unordered_set<string> dict={wordList.begin(), wordList.end()};
    int steps = 1;

    dict.erase(beginWord);
    while (!Q.empty()){
      int num=Q.size();
      for (int i=0; i<num; i++){
        string cur = Q.front();
        if (cur == endWord)
          return steps;
        Q.pop();
        
        int n=cur.size();
        for (int j=0; j<n; j++){
          char tmp = cur[j];
          for (char ch='a'; ch<='z'; ch++){
            cur[j] = ch;
            if (dict.count(cur)){
              Q.push(cur);
              dict.erase(cur);
            }
          }
          cur[j] = tmp;
        }
      
      }
      steps++;
    }
    return 0;
  }
};
