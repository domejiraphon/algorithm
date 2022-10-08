#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <list>

using namespace std;

class Trie {
private:
  unordered_set<string> Set;
public:
  Trie() {
      
  }
  
  void insert(string word) {
      
  }
  
  bool search(string word) {
      
  }
  
  bool startsWith(string prefix) {
      
  }
};

int main()
{
  Trie* obj = new Trie();
  obj->insert("apple");
  cout << obj->search("apple") << endl;
  cout << obj->startsWith("app") << endl;
}
