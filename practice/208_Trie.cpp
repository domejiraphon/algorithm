struct Node {
  char ch;
  Node* children[26];
  bool end;

  Node (char cha){
    ch = cha;
    for (int i=0; i<26; i++)
      children[i] = nullptr;
    end=false;
  }
};

class Trie {
  Node* root;
public:
  Trie() {
    root = new Node('\0');
  }
  
  void insert(string word) {
    string cur = word;
    insertUtils(root, cur, 0);
  }

  void insertUtils(Node* root, string& word, int i){
    if (i == word.size()){
      root -> end = true;
      return;
    }
    Node* child;
    if (root -> children[word[i] - 'a'])
      child = root -> children[word[i] - 'a'];
    else{
      child = new Node(word[i]);
      root -> children[word[i] - 'a'] = child;
    }
    insertUtils(child, word, i + 1);
      
  }
  
  bool search(string word) {
    return searchUtils(root , word, 0);
  }
  
  bool searchUtils(Node* root, string& word, int i){
    if (i == word.size())
      return root -> end;
    bool out=false;
    if (root -> children[word[i] - 'a'])
      out = searchUtils(root -> children[word[i] - 'a'], word, i + 1);
    return out;
  }

  bool startsWith(string prefix) {
    return prefixUtils(root, prefix, 0);
  }

  bool prefixUtils(Node* root, string& word, int i){
    if (i == word.size())
      return true;
    bool out=false;
    if (root -> children[word[i] - 'a'])
      out = prefixUtils(root -> children[word[i] - 'a'], word, i + 1);
    return out;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */