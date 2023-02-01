#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class myComparator{
public:
  int operator() (int a, int b){return a < b;}};


class Solution {
public:
  int minSetSize(vector<int>& arr) {
    priority_queue<int, vector<int>, myComparator> maxHeap;
    map<int, int> hashTable;
    for (int i=0; i != arr.size(); i++){
      if (hashTable.find(arr[i]) == hashTable.end()){hashTable[arr[i]] = 1;}
      else {hashTable[arr[i]]++;}
    }
    for (auto it=hashTable.begin(); it != hashTable.end(); it++){
      maxHeap.push(it -> second);
    }
    int cur= arr.size();
    int count(0);
    while (cur > (int) arr.size()/2){
      cur -= maxHeap.top();
      count++;
      maxHeap.pop();
    }
    return count;
  }
};

int main()
{
  vector<int> arr = {3,3,3,3,5,5,5,2,2,7};
  
  Solution sol;
  cout << sol.minSetSize(arr) << endl;

  arr = vector<int> {1,9};
  cout << sol.minSetSize(arr) << endl;

  
  return 0;
}