#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
template <typename T>
void print(const vector<T> & vec)
{
    for(auto ele : vec)
    {
      cout << ele << ", ";
    }
    cout <<endl;
    
}
void print(vector<tuple<int, string>> vec)
{
    for(auto ele : vec)
    {
      cout << get<0>(ele) << ", "<< get<1>(ele)<< endl;
    }
    cout <<endl;
  
}

class myComparator{
public:
  int operator() (tuple<int, string> p1, tuple<int, string> p2){
    if (get<0>(p1) != get<0>(p2)) {return get<0>(p1) < get<0>(p2);}
    else {return get<1>(p1) > get<1>(p2);}
    }
};

class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> hashTable;
    for (auto i: words){
      if (hashTable.find(i) == hashTable.end()){
        hashTable[i] = 0;
      }
      else {hashTable[i]++;}
    }
    priority_queue<tuple<int, string>, vector<tuple<int, string>>, myComparator> maxHeap;
    for (auto it= hashTable.begin(); it != hashTable.end(); it++){
      maxHeap.push(tuple<int, string> {it -> second, it -> first});
    }

    int counter(0);
    words.clear();
    while (!maxHeap.empty()){
      tuple<int, string> p = maxHeap.top();
      words.push_back(get<1>(p));
      maxHeap.pop();
      counter++;
      if (counter==k){break;}
    }
   
    return words;
  }
};

int main()
{ 
  Solution* sol;
  vector<string> words = {"i","love","leetcode","i","love","coding"};
  vector<string> out = sol -> topKFrequent(words, 2);
  print(out);

  words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
  out = sol -> topKFrequent(words, 4);
  print(out);
  return 0;
}