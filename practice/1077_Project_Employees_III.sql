/*
1077. Project Employees III
Table: Project

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) is the primary key of this table.
employee_id is a foreign key to Employee table.
Each row of this table indicates that the employee with employee_id is working on the project with project_id.
 

Table: Employee

+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id is the primary key of this table.
Each row of this table contains information about one employee.
 

Write an SQL query that reports the most experienced employees in each project. In case of a tie, report all employees with the maximum number of experience years.

Return the result table in any order.
*/
# Write your MySQL query statement below
SELECT 
  project_id,
  E.employee_id
FROM 
  Project P
JOIN 
  Employee E
ON 
  P.employee_id = E.employee_id
WHERE
  (project_id, experience_years) IN (SELECT 
                p.project_id, 
                MAX(e.experience_years) AS max 
              FROM
                Project p
              JOIN
                Employee e
              ON
                p.employee_id = e.employee_id
              GROUP BY
                p.project_id)
  
  

