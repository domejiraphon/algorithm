/*
184. Department Highest Salary
Table: Employee

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id is the primary key column for this table.
departmentId is a foreign key of the ID from the Department table.
Each row of this table indicates the ID, name, and salary of an employee. It also contains the ID of their department.
 

Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table. It is guaranteed that department name is not NULL.
Each row of this table indicates the ID of a department and its name.
 

Write an SQL query to find employees who have the highest salary in each of the departments.

Return the result table in any order.
*/
# Write your MySQL query statement below
SELECT T.Department,
  e.name AS Employee, 
  T.Salary
FROM 
  (SELECT 
      departmentId, 
      Department.name AS Department,
      MAX(salary) AS Salary
    FROM Department, Employee
    WHERE Department.id = Employee.departmentId
    GROUP BY Department.id) AS T, 
  Employee e 
  WHERE e.salary = T.Salary AND e.departmentId = T.departmentId



