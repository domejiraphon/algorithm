class FirstUnique {
private:
  unordered_map<int, int> freq;
  queue<int> Q;
public:
  FirstUnique(vector<int>& nums) {
    for (auto ele: nums){freq[ele]++;Q.push(ele);}
  }

  int showFirstUnique() {
    while (!Q.empty()){
      if (freq[Q.front()] == 1){
        return Q.front();
      }
      Q.pop();
    }
    return -1;
  }

  void add(int value) {
    freq[value]++;
    Q.push(value);
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */