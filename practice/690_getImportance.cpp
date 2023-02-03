/*
690. Employee Importance
You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.
*/
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
  int getImportance(vector<Employee*> employees, int id) {
    
    int n=employees.size();
    unordered_map<int, Employee*> map;
    for (int i=0; i<n; i++)
      map[employees[i] -> id] = employees[i];
    
    return dfs(map, id);
  }
private:
  int dfs(unordered_map<int, Employee*>& map, int cur){
    int sum=map[cur] -> importance;
    for (auto next: map[cur] -> subordinates)
      sum += dfs(map, next);
    return sum;
  }
};
