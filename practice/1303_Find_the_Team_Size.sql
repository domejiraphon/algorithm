/*
1303. Find the Team Size
Table: Employee

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| employee_id   | int     |
| team_id       | int     |
+---------------+---------+
employee_id is the primary key for this table.
Each row of this table contains the ID of each employee and their respective team.
 

Write an SQL query to find the team size of each of the employees.

Return result table in any order.
*/
# Write your MySQL query statement below
SELECT
  employee_id,
  team_size
FROM Employee, 
(SELECT 
  team_id, COUNT(team_id) AS team_size
FROM 
  Employee 
GROUP BY 
  team_id) AS T
WHERE Employee.team_id = T.team_id
