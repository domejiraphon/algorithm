/*
588. Design In-Memory File System
Design a data structure that simulates an in-memory file system.

Implement the FileSystem class:

FileSystem() Initializes the object of the system.
List<String> ls(String path)
If path is a file path, returns a list that only contains this file's name.
If path is a directory path, returns the list of file and directory names in this directory.
The answer should in lexicographic order.
void mkdir(String path) Makes a new directory according to the given path. The given directory path does not exist. If the middle directories in the path do not exist, you should create them as well.
void addContentToFile(String filePath, String content)
If filePath does not exist, creates that file containing given content.
If filePath already exists, appends the given content to original content.
String readContentFromFile(String filePath) Returns the content in the file at
*/
struct fileNode {
  unordered_map<string, fileNode*> next;
  bool isFile=false;
  string content="";
};

class FileSystem {
  fileNode* root;
public:
  FileSystem() {
    root = new fileNode();
  }
  
  fileNode* goToPath(string path){
    fileNode* curPath = root;
    int n=path.size();
    string cur="";
    for (int i=1; i<=n; i++){
      if ((i == n && cur != "") || path[i] == '/'){
        if (!curPath -> next.count(cur)){
          curPath -> next[cur] = new fileNode();
        }
        curPath = curPath -> next[cur];
        cur = "";
      }
      else 
        cur += path[i];
    }
    
    return curPath;
  }
  vector<string> ls(string path) {
    fileNode* curPath = goToPath(path);
    if (curPath -> isFile){
      string cur="";
      int i=path.size()-1;
      while(path[i] != '/')
        cur = path[i--] + cur;
      return {cur};
    }
    
    vector<string> ans;
    unordered_map<string, fileNode*> cur=curPath -> next;
    for (auto it=cur.begin(); it != cur.end(); it++)
      ans.push_back(it -> first);
    sort(ans.begin(), ans.end());
    return ans;
  }
  
  void mkdir(string path) {
    goToPath(path);
  }
  
  void addContentToFile(string filePath, string content) {
    fileNode* curPath = goToPath(filePath);
    curPath -> isFile = true;
    curPath -> content += content;
  }
  
  string readContentFromFile(string filePath) {
    fileNode* curPath = goToPath(filePath);
    if (curPath -> isFile)
      return curPath -> content;
    return "";
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
