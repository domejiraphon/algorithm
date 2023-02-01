/*
126. Word Ladder II
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
*/

class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words={wordList.begin(), wordList.end()};
    vector<vector<string>> ans;
    int path = INT_MAX;
    queue<vector<string>> q;
    q.push({beginWord});

    words.erase(beginWord);
    while (!q.empty()){
      auto cur = q.front();
      q.pop();
      if (cur.size() > path)
        continue;
      auto prev = cur.back();
      words.erase(prev);
      if (prev == endWord){
        if (cur.size() < path)
          ans.clear();
        ans.push_back(cur);
        path = cur.size();
        continue;
      }
      for(int i=0; i<prev.size(); ++i) {
        for(char ch='a'; ch<='z'; ++ch){
          string copy = prev;
          copy[i] = ch;
          if(ch != prev[i] && words.count(copy)){
            cur.push_back(copy);
            q.push(cur);
            cur.pop_back();
          }
        }
      }
    }
    return ans;
  }
};
