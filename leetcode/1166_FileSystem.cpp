#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

void print(vector<string> path){
  for (auto ele: path){
    cout << ele << ", ";
  }
  cout << endl;
}
void print(unordered_map<string, int> hashTable){
  for (auto it =hashTable.begin(); it != hashTable.end(); it++){
    cout << it -> first << ", " << it -> second;
  }
  cout << endl;
}
class FileSystem {
  unordered_map<string, int> hashTable;
public:
  FileSystem() {
      
  }
  
  bool createPath(string path, int value) {
    string delimiter = "/";
    size_t pos = 0;
    string token; string tmp = path;
    path = path.substr(1, path.size() - 1) + "/";
    vector<string> cache;
    while ((pos = path.find(delimiter)) != string::npos) {
      token = "/" + path.substr(0, pos);
      cache.push_back(token);
      path.erase(0, pos + delimiter.length());
    }
   
    for (int i=0; i < cache.size() - 1; i++){
      if (hashTable.find(cache[i]) == hashTable.end()){return false;}
    }
    hashTable[tmp] = value;
    return true;
  }
  
  int get(string path) {
    if (hashTable.find(path) != hashTable.end()){
      return hashTable[path];
    }
    return -1;
  }
};

int main()
{
  
  FileSystem* obj = new FileSystem();
  cout << obj->createPath("/leet", 1)<< endl;
  cout << obj->createPath("/leet/code", 2)<< endl;
  
  cout << obj -> get("/leet/code")<< endl;

  cout << obj->createPath("/c/d", 1)<< endl;
  cout << obj->get("/c")<< endl;
  return 0;
}