class FileSystem {
  unordered_map<string, int> paths;
public:
  FileSystem() {
      
  }
  
  bool createPath(string path, int value) {
    if (path == "" || path == "/")
      return false;
    if (!paths.count(path) && checkPrev(path)){
      paths[path] = value;
      return true;
    }
    return false;
  }
  
  int get(string path) {
    return paths.count(path) ? paths[path] : -1;
  }

  bool checkPrev(string path){
    int n=path.size();
    int i=n-1;
    while (i >=0 && path[i] != '/')
      i--;
    
    if (i == 0)
      return true;

    string prevPath = path.substr(0, i);
    
    return paths.count(prevPath);
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */