/*
1244. Design A Leaderboard

Design a Leaderboard class, which has 3 functions:

addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
top(K): Return the score sum of the top K players.
reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
Initially, the leaderboard is empty.


*/
class Compare {
public:
  bool operator () (int a, int b){
    return a > b;
  }
};

class Leaderboard {
  map<int, int> ranking;
public:
  Leaderboard() {
      
  }
  
  void addScore(int playerId, int score) {
    ranking[playerId] += score;
  }
  
  int top(int K) {
    priority_queue<int, vector<int>, Compare> minHeap;
    
    for (auto it=ranking.begin(); it != ranking.end(); it++){
      minHeap.push(it -> second);
      if (minHeap.size() > K)
        minHeap.pop();
    }
    int sum=0;
    while (!minHeap.empty()){
      sum += minHeap.top();
      minHeap.pop();
    }
    return sum;
  }
  
  void reset(int playerId) {
    ranking.erase(playerId);
  }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

struct Compare {
  bool operator () (const pair<int, int> a, const pair<int, int> b) const {
    return a.second > b.second;
  }
};


class Leaderboard {
  unordered_map<int, int> ranking;
  set<pair<int, int>> S;
public:
  Leaderboard() {
      
  }
  
  void addScore(int playerId, int score) {
    S.erase({ranking[playerId], playerId});
    ranking[playerId] += score;
    S.insert({ranking[playerId], playerId});
  }
  
  int top(int K) {
    int i=0;
    int sum=0;
    for (auto it=S.rbegin(); it!= S.rend() && i<K; it++){
      sum += it ->first;
      i++;
    }
    return sum;
  }
  
  void reset(int playerId) {
    S.erase({ranking[playerId], playerId});
    ranking[playerId] = 0;
  }
};
