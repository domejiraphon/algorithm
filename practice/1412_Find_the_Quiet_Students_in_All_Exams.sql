/*
1412. Find the Quiet Students in All Exams
Table: Student

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| student_id          | int     |
| student_name        | varchar |
+---------------------+---------+
student_id is the primary key for this table.
student_name is the name of the student.
 

Table: Exam

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| exam_id       | int     |
| student_id    | int     |
| score         | int     |
+---------------+---------+
(exam_id, student_id) is the primary key for this table.
Each row of this table indicates that the student with student_id had a score points in the exam with id exam_id.
 

A quiet student is the one who took at least one exam and did not score the high or the low score.

Write an SQL query to report the students (student_id, student_name) being quiet in all exams. Do not return the student who has never taken any exam.

Return the result table ordered by student_id.
*/
WITH T AS (SELECT
            e.exam_id,
            s.student_id,
            s.student_name,
            e.score,
            RANK() OVER(PARTITION BY e.exam_id ORDER BY e.score ASC) AS lowest,
            RANK() OVER(PARTITION BY e.exam_id ORDER BY e.score DESC) AS highest
          FROM
            Student s
          LEFT JOIN
            Exam e 
          ON
            e.student_id = s.student_id)
SELECT
  student_id,
  student_name
FROM
  Student
WHERE
  student_id NOT IN (SELECT DISTINCT student_id FROM T WHERE lowest = 1 OR highest = 1)
ORDER BY 
  student_id




