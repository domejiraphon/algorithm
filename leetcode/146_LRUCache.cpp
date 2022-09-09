#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class LRUCache {
  map<int, int> cache;
  int cap;
  queue<int> Q;
public:
  LRUCache(int capacity) {
    map<int, int> cache;
    int cap = capacity;
   
  }
  
  int get(int key) {
    if (cache.find(key) != cache.end()){
      Q.push(key);
      return cache[key];
    }
    else {return -1;}
  }
  
  void put(int key, int value) {
    if (cache.size() <= cap - 1){
      cache[key] = value;
    }
    else {
      int least_used = Q.front();
      cache.erase(key);
      Q.pop();
      cache[key] = value;
    }
  }
};

int main()
{
  int capacity = 2;
  LRUCache* obj = new LRUCache(capacity);
  int param_1 = obj->get(1);
  obj->put(1, 2);
  
  return 0;
}