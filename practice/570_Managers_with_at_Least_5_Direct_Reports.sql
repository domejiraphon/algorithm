/*
570. Managers with at Least 5 Direct Reports
Table: Employee

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the name of an employee, their department, and the id of their manager.
If managerId is null, then the employee does not have a manager.
No employee will be the manager of themself.
 

Write an SQL query to report the managers with at least five direct reports.

Return the result table in any order.
*/
# Write your MySQL query statement below
SELECT name 
FROM Employee, 
(SELECT managerId, COUNT(managerId) AS reports
  FROM Employee 
  WHERE managerId IS NOT NULL
  GROUP BY managerId) AS T
WHERE T.managerId = Employee.id AND T.reports >= 5
