/*
1112. Highest Grade For Each Student
Table: Enrollments

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| course_id     | int     |
| grade         | int     |
+---------------+---------+
(student_id, course_id) is the primary key of this table.
grade is never NULL.
 

Write a SQL query to find the highest grade with its corresponding course for each student. In case of a tie, you should find the course with the smallest course_id.

Return the result table ordered by student_id in ascending order.
*/
SELECT student_id, 
  MIN(course_id) AS course_id,
  grade 
FROM Enrollments
WHERE (student_id, grade) IN (SELECT student_id, MAX(grade) AS grade
  FROM Enrollments
  GROUP BY student_id)
GROUP BY student_id, grade
ORDER BY student_id;
