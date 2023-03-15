/*
1731. The Number of Employees Which Report to Each Employee
Table: Employees

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| employee_id | int      |
| name        | varchar  |
| reports_to  | int      |
| age         | int      |
+-------------+----------+
employee_id is the primary key for this table.
This table contains information about the employees and the id of the manager they report to. Some employees do not report to anyone (reports_to is null). 
 

For this problem, we will consider a manager an employee who has at least 1 other employee reporting to them.

Write an SQL query to report the ids and the names of all managers, the number of employees who report directly to them, and the average age of the reports rounded to the nearest integer.
*/
# Write your MySQL query statement below
SELECT
  e1.employee_id,
  e1.name,
  COUNT(e2.employee_id) AS reports_count,
  ROUND(AVG(e2.age), 0) AS average_age
FROM
  Employees e1
JOIN
  Employees e2
ON
  e2.reports_to IS NOT NULL AND e1.employee_id = e2.reports_to
GROUP BY
  e1.employee_id
ORDER BY
  e1.employee_id

