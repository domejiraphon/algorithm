class HitCounter {
private:
  int count = 0;
  deque<pair<int, int>> hits;
public:
  HitCounter() {
  }

  void hit(int timestamp) {
    if (hits.front().first == timestamp){
      pair<int, int> prev = hits.back();
      hits.pop_back();
      hits.push_back({prev.first, prev.second + 1});
    }
    else {
      hits.push_back({timestamp, 1});
    }
    count++;
  }

  int getHits(int timestamp) {
    while (!hits.empty() && hits.front().first <= timestamp - 300){
      count -= hits.front().second;
      hits.pop_front();
    }
    return count;
  }
};

class HitCounter2 {
private:
  vector<int> counter;
public:
  HitCounter2() {
  }

  void hit(int timestamp) {
    counter.push_back(timestamp);
  }

  int getHits(int timestamp) {
    int idx = lower_bound(counter.begin(), counter.end(), timestamp - 300 + 0.001) - counter.begin();
    return counter.size() - idx;
  }
};
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */