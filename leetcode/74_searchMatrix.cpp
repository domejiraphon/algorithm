#include <iostream>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix[0].size(), m=matrix.size();
    
    int left(0), right(n*m - 1);
    int idx, mid;
    while (left <= right){
      idx = (int) (left + right) / 2;
      mid = matrix[idx / n][idx % n];
      if (target == mid){
        return true;
      }
      else if (target < mid){
        right = idx - 1;
        
      }
      else {
        left = idx + 1;
      }
    }
    return false;
  }
};
int main()
{
  Solution* sol;
  vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};

  cout << sol -> searchMatrix(matrix, 13) << endl;
}