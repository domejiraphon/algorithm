


class TimeMap {
private:
  unordered_map<string, map<int, string>> hash;
public:
  TimeMap() {

  }

  void set(string key, string value, int timestamp) {
    hash[key][timestamp] = value;
  }

  string get(string key, int timestamp) {
    if (!hash.count(key)){return "";}
   
    auto it = hash[key].upper_bound(timestamp);
    if (it == hash[key].begin()) {return "";}
    
    return prev(it) -> second;
  }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
