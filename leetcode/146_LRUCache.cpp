#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class LRUCache {
  int cap;
  queue<int> Q;
  map<int, int> cache;
public:
  LRUCache(int capacity) {
    cap = capacity;
  }
  
  int get(int key) {
    if (cache.find(key) != cache.end()){
      Q.push(key);
      return cache[key];
    }
    else {return -1;}
  }
  
  void put(int key, int value) {
    if (cache.size() == cap){
      cache.erase(Q.front());
      Q.pop();
    }
    cache[key] = value;
    Q.push(key);
  }

  void print(){
    for (auto it=cache.begin(); it != cache.end(); it++){
      cout << it -> first << ", "<< it -> second << endl;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main()
{
  int capacity = 4;
  LRUCache* obj = new LRUCache(capacity);
  cout << obj->get(1)<< endl;
  obj->put(1, 2); obj->put(2, 3); obj->put(3, 5); obj->put(5, 56); 
  obj -> print();
  cout << endl;
  obj->put(6, 56);
  obj -> print();
  return 0;
}