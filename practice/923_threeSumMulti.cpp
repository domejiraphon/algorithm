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

void print(vector<int> cur){
  for (auto it : cur){cout << it<<", ";}
  cout << endl;
}

void print(map<int, int> cur){
  for (auto it =cur.begin(); it != cur.end(); it++){cout << it -> first <<", "<< it -> second<<endl;}
  cout << endl;
}
class Solution {
public:
  int threeSumMulti(vector<int>& arr, int target) {
    int count(0);
    map<int, int> hashTable;
    set<int> S;
    for (int i=0; i != arr.size(); i++){
      if (hashTable.find(arr[i]) == hashTable.end()){hashTable[arr[i]] = 1;}
      else {hashTable[arr[i]]++;}
      S.insert(arr[i]);
    }
    
    arr.clear();
    for (auto it: S){arr.push_back(it);}
    
    int n=arr.size();
    for (int i=0; i != n; i++){
      int low(0), high(n - 1);
     
      while(low < high){
        if (arr[low] + arr[high] < target - arr[i]){
          low++;
        }
        else if (arr[low] + arr[high] == target - arr[i]){
          cout << arr[i] << ", "<< arr[low]<< ", "<< arr[high]<<endl;
          int cur(hashTable[arr[i]]);
          if (arr[i] != arr[low]) {cur *= hashTable[arr[low]];}
          if (arr[i] != arr[high]) {cur *= hashTable[arr[high]];}
          count +=  cur;
          high--; low++;
        }
        else {high--;}
        //cout << low <<", " << high<<endl;
      }
      
    }
    cout << count;
    exit(0);
    return count;
  }
};

int main()
{
  vector<int> arr={1,1,2,2,3,3,4,4,5,5};
  Solution sol;
  cout << sol.threeSumMulti(arr, 8)<< endl;
  exit(0);
  arr = vector<int> {1,1,2,2,2,2};
  cout << sol.threeSumMulti(arr, 5)<< endl;

  arr = vector<int> {2,1,3};
  cout << sol.threeSumMulti(arr, 6)<< endl;
  
  return 0;
}