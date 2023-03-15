/*
580. Count Student Number in Departments
Table: Student

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| student_id   | int     |
| student_name | varchar |
| gender       | varchar |
| dept_id      | int     |
+--------------+---------+
student_id is the primary key column for this table.
dept_id is a foreign key to dept_id in the Department tables.
Each row of this table indicates the name of a student, their gender, and the id of their department.
 

Table: Department

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| dept_id     | int     |
| dept_name   | varchar |
+-------------+---------+
dept_id is the primary key column for this table.
Each row of this table contains the id and the name of a department.
 

Write an SQL query to report the respective department name and number of students majoring in each department for all departments in the Department table (even ones with no current students).

Return the result table ordered by student_number in descending order. In case of a tie, order them by dept_name alphabetically.
*/
# Write your MySQL query statement below
SELECT 
  d.dept_name, IFNULL(T.student_number, 0) AS student_number
  FROM Department d 
  LEFT JOIN
    (SELECT 
      dept_id, 
      COUNT(student_id) AS student_number
    FROM 
      Student 
    GROUP BY
      dept_id)
    AS T
  ON d.dept_id = T.dept_id
  ORDER BY 
    student_number DESC,
    d.dept_name ASC
