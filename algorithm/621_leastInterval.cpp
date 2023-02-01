/*
621. Task Scheduler
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.
*/
bool sortby(int& a, int& b){
  return a > b;
}
class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (auto task: tasks)
      freq[task - 'A']++;
    sort(freq.begin(), freq.end(), sortby);
    int fMax = freq[0];
    int idle = (fMax - 1) * n;
    
    for (int i=1; i<26 && freq[i] != 0 && idle >= 0; i++){
      idle -= min(fMax - 1, freq[i]);
    } 
    idle = max(idle, 0);
    return tasks.size() + idle;
  }
};