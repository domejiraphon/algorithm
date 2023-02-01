class Comparator {
public:
  int operator () (int a, int b){
    return a > b;
  }
};

class Solution {
public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    map<int, priority_queue<int, vector<int>, Comparator>> scores;
    for (auto item: items){
      if (scores[item[0]].size() >= 5){
        int least = scores[item[0]].top();
        if (least < item[1]){
          scores[item[0]].pop();
          scores[item[0]].push(item[1]);
        }
      }
      else {
        scores[item[0]].push(item[1]);
      }
    }
    vector<vector<int>> res;
    for (auto it=scores.begin(); it != scores.end(); it++){
      int sum(0);
      while (!(it ->second.empty())){
        sum += it -> second.top();
        it ->second.pop();
      }
      res.push_back(vector<int> {it -> first, sum / 5});
    }
    return res;
  }
};
