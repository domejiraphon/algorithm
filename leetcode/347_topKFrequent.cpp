#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;
void print(vector<int> x){
  for (auto row: x){cout << row <<", ";}
  cout << endl;
}

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem<<", ";
    }
    cout << endl;
  }
}



class myComparator{
public:
  int operator() (tuple<int, int> p1, tuple<int, int> p2){
    return get<1>(p1) < get<1>(p2);}
};

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> hashTable;
    for (auto i: nums){
      if (hashTable.find(i) == hashTable.end()){
        hashTable[i] = 0;
      }
      else {hashTable[i]++;}
    }
    nums.clear();
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, myComparator> maxHeap;
    for (auto it= hashTable.begin(); it != hashTable.end(); it++){
      tuple<int, int> cur = {it -> first, it -> second};
      maxHeap.push(cur);
    }

    int counter(0);
    while (!maxHeap.empty()){
      tuple<int, int> p = maxHeap.top();
      nums.push_back(get<0>(p));
      maxHeap.pop();
      counter++;
      if (counter==k){break;}
    }
    return nums;
  }
};

int main()
{
  vector<int> nums={1,1,1,2,2,3};
  
  Solution sol;
  vector<int> out;
  out = sol.topKFrequent(nums, 2);
  print(out);
  return 0;
}