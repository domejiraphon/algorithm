/**
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * 
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * 
 * void put(int key, int value) Update the value of the key if the key exists. 
 * Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity 
 * from this operation, evict the least recently used key. 
 * The functions get and put must each run in O(1) average time complexity.
*/
struct Node {
  int key;
  int val;
  Node* prev;
  Node* next;
  Node(int k, int v) {key = k; val = v;}
};

class LRUCache {
private:
  int cap;
  Node* head = new Node(INT_MIN, INT_MIN);
  Node* tail = new Node(INT_MIN, INT_MIN);
  unordered_map<int, Node*> cache;
public:
  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  int get(int key) {
    if (cache.count(key)){
      Node* tmp = cache[key];
      removeNode(tmp);
      addNode(tmp);
      return tmp -> val;
    }
    else {
      return -1;
    }
  }

  void put(int key, int value) {
    if(cache.count(key)){
      removeNode(cache[key]);
      cache.erase(key);
    }
    if (cache.size() == cap){
      Node* last = tail -> prev;
      removeNode(last);
      cache.erase(last -> key);
    }
    Node* cur = new Node(key, value);
    cache[key] = cur;
    addNode(cur);
  }
private:
  void addNode(Node* newNode){
    Node* prevTmp = head -> next;
    head -> next = newNode;
    newNode -> next = prevTmp;
    newNode -> prev = head;
    prevTmp -> prev = newNode;
  }
  
  void removeNode(Node* delNode){
    Node* prevTmp = delNode -> prev;
    Node* nextTmp = delNode -> next;
    prevTmp -> next = nextTmp;
    nextTmp -> prev = prevTmp;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */