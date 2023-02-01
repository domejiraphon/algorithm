/*
460. LFU Cache
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/
class LFUCache {
  unordered_map<int, list<pair<int, int>>> freq;
  unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
  int capacity, minF;
  void insert(int key, int value, int frequencies){
    freq[frequencies].push_back({key, value});
    cache[key] = {frequencies, --freq[frequencies].end()};
  }
public:
  LFUCache(int cap) {
    capacity=cap;
    minF = 0;
  }
  
  int get(int key) {
    if (!cache.count(key))
      return -1;
    int f = cache[key].first;
    auto it = cache[key].second;
    pair<int, int> cur = *it;
    freq[f].erase(it);
    if (freq[f].empty() && f == minF){
      minF++;
    }
    insert(key, cur.second, f + 1);
    return cur.second;
  }
  
  void put(int key, int value) {
    if (capacity <=0)
      return;
    if (cache.count(key)){
      cache[key].second ->second = value;
      get(key);
      return;
    }
    if (cache.size() == capacity){
      cache.erase(freq[minF].front().first);
      freq[minF].pop_front();
    }
    minF = 1;
    insert(key, value, 1);
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
