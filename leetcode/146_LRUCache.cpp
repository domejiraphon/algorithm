#include <iostream>
#include <iterator>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class LRUCache {
  size_t capacity;
  int curCap;
  unordered_map<int,  list<pair<int, int>>::iterator> m_map; 
  list<pair<int, int>> m_list;  
public:
  LRUCache(int capacity) {
    capacity = capacity;
  }
  
  int get(int key) {
    auto it = m_map.find(key);
    if (it == m_map.end()){return -1;}
    m_list.remove()
    return it -> second -> second;
  }
  
  void put(int key, int value) {
    auto it = m_map.find(key);
    if (it != m_map.end()){
      it -> second -> second = value;
      return;
    }
    if (curCap == capacity){
      m_list.pop_back();
      int key_to_del = m_list.back().first; 
      m_map.erase(key_to_del);
    }
    m_list.emplace_front(key, value);
    m_map[key] = m_list.begin();
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