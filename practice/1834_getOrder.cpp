/*
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

If the CPU is idle and there are no available tasks to process, the CPU remains idle.
If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
Once a task is started, the CPU will process the entire task without stopping.
The CPU can finish a task then start a new one instantly.
Return the order in which the CPU will process the tasks.
*/
class Compare {
public:
  bool operator() (pair<int, int>& a, pair<int, int>& b){
    return a.second == b.second ? a.first > b.first : a.second > b.second;
  }
};

class Solution {
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n=tasks.size();
    for (int i=0; i<n; i++)
      tasks[i].push_back(i);
    sort(tasks.begin(), tasks.end());
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
    
    long long t = tasks[0][0];
    
    int i=0;
    for (; i<n; i++){
      if (tasks[i][0] != t)
        break;
      minHeap.push({tasks[i][2], tasks[i][1]});
    }
    
    
    vector<int> res;
    while (res.size() < n){
      if (!minHeap.empty()){
        pair<int, int> cur = minHeap.top();
        
        minHeap.pop();
        res.push_back(cur.first);
        t += cur.second;
      }
      else {
        if (t < tasks[i][0])
          t = tasks[i][0];
      }
      for (; i<n; i++){
        if (tasks[i][0] <= t)
          minHeap.push({tasks[i][2], tasks[i][1]});
        else
          break;
      }   
    }
    return res;
  }
};
