struct Node {
  int key, val;
  Node* next;
  Node (int k, int v){
    key = k; 
    val = v;
    next = nullptr;
  }
};

class MyHashMap {
public:
  const static int size = 10037;
  const static int multiplier = 19753;
  Node* hashMap[size] = {};

  int hash(int key){
    return ((long) key * multiplier % size);
  }
  MyHashMap() {
    
  }
  
  void put(int key, int value) {
    remove(key);
    int newKey = hash(key);
    Node* node = new Node(key, value);
    node -> next = hashMap[newKey];
    hashMap[newKey] = node;
  }
  
  int get(int key) {
    int newKey = hash(key);
    Node* cur = hashMap[newKey];
    while (cur){
      if (cur -> key == key)
        return cur -> val;
      cur = cur -> next;
    }
    return -1;
  }
  
  void remove(int key) {
    int newKey = hash(key);
    Node* cur = hashMap[newKey];
    if (!cur)
      return;
    if (cur -> key == key){
      hashMap[newKey] = cur -> next;
      delete cur;
      return;
    }
    while (cur && cur -> next){
      if (cur -> next -> key == key){
        Node* temp = cur -> next;
        cur -> next = temp -> next;
        delete temp;
      }
      cur = cur -> next;
    }
  }
};

class MyHashMap {
  vector<int> hash;
public:
  MyHashMap() {
    hash.resize(1000001, -1);
  }
  
  void put(int key, int value) {
    hash[key] = value;
  }
  
  int get(int key) {
    return hash[key];
  }
  
  void remove(int key) {
    hash[key] = -1;
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
