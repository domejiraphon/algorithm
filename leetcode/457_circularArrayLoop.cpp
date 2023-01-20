/*
457. Circular Array Loop
You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:

If nums[i] is positive, move nums[i] steps forward, and
If nums[i] is negative, move nums[i] steps backward.
Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
Every nums[seq[j]] is either all positive or all negative.
k > 1
Return true if there is a cycle in nums, or false otherwise.
*/
class Solution {
public:
  bool circularArrayLoop(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> graphs(n);
    for (int i=0; i<n; i++){
      int steps = (i + nums[i]) % n;
      while (steps < 0)
        steps += n;
      if (steps != i)
        graphs[i].push_back(steps);
    }
    vector<bool> visited(n, false);
    vector<char> status(n, 'u');
    for (int i=0; i<n; i++){
      if (!visited[i]){
        visited[i] = true;
        if (isCycle(graphs, i, visited, status, nums))
          return true;
      }
    }
    return false;
  }
private:
  bool isCycle(vector<vector<int>>& graphs, int cur, vector<bool>& visited, vector<char>& status, vector<int>& nums){
    status[cur] = 'a';
    for (auto neigh: graphs[cur]){
      if (status[neigh] == 'a'){
        return true;
      }
        
      if (!visited[neigh] && nums[neigh] * nums[cur] > 0){
        visited[neigh] = true;
        if (isCycle(graphs, neigh, visited, status, nums))
          return true;
      }
    }
    status[cur] = 'd';
    return false;
  }
};