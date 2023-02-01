#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution2 {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    vector<int> flatten;
    for (int i=0; i < matrix.size(); i++){
      flatten.insert(flatten.end(), matrix[i].begin(), matrix[i].end());
    }
    sort(flatten.begin(), flatten.end());
    return flatten[k];
  }
};

class compare {
public:
  int operator () (pair<int, int> a, pair<int, int> b){
    return a.second > b.second;}
};

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i=0; i < n; i++){
      minHeap.push({i, matrix[i][0]});
    }
    vector<int> idx(n, 0);
    pair<int, int> minCur;
    int row;
    while (k > 0){
      minCur = minHeap.top();
      minHeap.pop();
      row = minCur.first;
      //idx[row]++;
      if (++idx[row] < m){
        minHeap.push({row, matrix[row][idx[row]]});
      }
      k--;
    }
    return minCur.second;
  }
};

int main()
{
  Solution* sol;

  vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
  cout << sol -> kthSmallest(matrix, 9)<< endl;
}
