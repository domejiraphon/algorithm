#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;

void print(vector<vector<int>> x){
  for (auto row: x){
    for (auto elem: row){
      cout << elem <<", ";}
    cout << endl;
  }
  
}

void print(map<string, vector<int>> x){
  for (auto it=x.begin(); it != x.end(); it++){
    cout << it -> first <<":";
    for(auto elem: it -> second){
      cout << elem << ", ";
    }
    cout << endl;
  }
}

class Solution {
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    unordered_set<int> set;
    for (int i=0; i != arr.size(); i++){
      set.insert(arr[i]);
    } 
    int count(0);
    for (int i=0; i != arr.size(); i++){
      count += helper(set, arr[i]);
    } 
   
    count += arr.size();
    return count;
  }
private:
  int helper(unordered_set<int> set, int head){
    int count(0);
    for (auto it=set.begin(); it != set.end(); it++){
      if (*it == head){continue;}
      if (head % *it == 0 && 
        set.find((int) head / *it) != set.end()){
          count++;
          //cout << "HEAD:"<<head << ", "<< *it << ", "<< (int) head / *it<< endl;
          count += helper(set, (int) head / *it);
          count += helper(set, *it);
        }
    }
    
    return count;
  }
};

int main()
{ 
  vector<int> arr = {2, 4};
  Solution* sol;
  cout << sol -> numFactoredBinaryTrees(arr)<<endl;

  arr = vector<int> {18,3,6,2};
  cout << sol -> numFactoredBinaryTrees(arr)<<endl;

  arr = vector<int> {2,4,5,10};
  cout << sol -> numFactoredBinaryTrees(arr)<<endl;
  
  return 0;
}