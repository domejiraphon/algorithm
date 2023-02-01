/*
705. Design HashSet
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/
struct Node {
  int val;
  Node* next={};
  Node(int k){
    val = k;
  }
};

class MyHashSet {
  const static int size = 13729;
  const static int mul = 9377;
public:
  Node* set[size] = {};
  MyHashSet() {
    
  }

  int hash(int key){
    return ((long) key * mul) % size;
  }

  void add(int key) {
    remove(key);
    int newKey = hash(key);
    Node* newNode = new Node(key);
    newNode -> next = set[newKey];
    set[newKey] = newNode;
  }
  
  void remove(int key) {
    int newKey = hash(key);
    Node* cur = set[newKey];
    if (!cur)
      return;

    if (cur -> val == key){
      set[newKey] = cur -> next;
      delete cur;
      return;
    }
    Node* prev = cur;
    while (cur && cur -> val != key){
      prev = cur;
      cur = cur -> next;
    }
    if (cur){
      prev -> next = cur -> next;
      delete cur;
    }
    
    return;
  }
  
  bool contains(int key) {
    int newKey = hash(key);
    Node* cur = set[newKey];
    while (cur){
      if (cur -> val == key)
        return true;
      cur = cur -> next;
    }
    return false;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
