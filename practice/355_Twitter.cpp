/*
355. Design Twitter
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
*/
class Twitter {
  vector<pair<int, int>> tweets;
  unordered_map<int, set<int>> friends;
public:
  Twitter() {
  
  }
  
  void postTweet(int userId, int tweetId) {
    tweets.push_back({userId, tweetId});
  }
  
  vector<int> getNewsFeed(int userId) {
    auto it = tweets.rbegin();
  
    vector<int> ans;
    while (ans.size() < 10 && it != tweets.rend()){
      pair<int, int> cur = *it;
      if (cur.first == userId || friends[userId].count(cur.first))
        ans.push_back(cur.second);
      it++;
    }
    return ans;
  }
  
  void follow(int followerId, int followeeId) {
    friends[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    friends[followerId].erase(followeeId);
  }
};

class Compare {
public:
  bool operator() (pair<int, int>& a, pair<int, int>& b){
    return a.first > b.first;
  }
};

class Twitter {
  map<int, vector<pair<int, int>>> tweets;
  unordered_map<int, set<int>> friends;
  int t;
public:
  Twitter() {
    t = 0;
  }
  
  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({t++, tweetId});
  }
  
  vector<int> getNewsFeed(int userId) {
    friends[userId].insert(userId);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    
    set<int> followings = friends[userId];
    for (auto it=followings.begin(); it != followings.end(); it++){
      if (!tweets.count(*it))
        continue;
      vector<pair<int, int>> cur = tweets[*it];
      for (int i=0; i<cur.size(); i++){
        minHeap.push(cur[i]);
        if (minHeap.size() > 10)
          minHeap.pop();
      }
    }
    
    vector<int> ans(minHeap.size());
    for (int i=ans.size() - 1; i>=0; i--){
      ans[i] = minHeap.top().second;
      minHeap.pop();
    }
    return ans;
  }
  
  void follow(int followerId, int followeeId) {
    friends[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    friends[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */