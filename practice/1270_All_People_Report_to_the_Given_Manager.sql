/*
1270. All People Report to the Given Manager
Table: Employees

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| employee_id   | int     |
| employee_name | varchar |
| manager_id    | int     |
+---------------+---------+
employee_id is the primary key for this table.
Each row of this table indicates that the employee with ID employee_id and name employee_name reports his work to his/her direct manager with manager_id
The head of the company is the employee with employee_id = 1.
 

Write an SQL query to find employee_id of all employees that directly or indirectly report their work to the head of the company.

The indirect relation between managers will not exceed three managers as the company is small.*/
# Write your MySQL query statement below
WITH RECURSIVE
  cte AS (
    (SELECT e1.employee_id FROM Employees e1 WHERE e1.manager_id = 1 AND e1.employee_id != 1)
    UNION ALL
    (SELECT 
      e2.employee_id 
    FROM 
      Employees e2
    JOIN
      cte e3
    WHERE
      e2.manager_id = e3.employee_id))

SELECT * FROM cte
----------------------------------------------
# Write your MySQL query statement below
SELECT
  e1.employee_id
FROM
  Employees e1
JOIN
  Employees e2 
ON 
  e1.employee_id != 1 AND e1.manager_id = e2.employee_id
JOIN
  Employees e3 
ON 
  e2.manager_id = e3.employee_id AND e3.manager_id = 1
