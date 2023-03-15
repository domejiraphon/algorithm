/*
626. Exchange Seats
Table: Seat

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the name and the ID of a student.
id is a continuous increment.
 

Write an SQL query to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.
*/
# Write your MySQL query statement below
SELECT
  (CASE WHEN (id %2) = 1 AND id != num.count THEN id + 1
      WHEN (id %2) = 1 AND id = num.count THEN id
      ELSE id - 1
  END) AS id,
  student
FROM
  Seat,
  (SELECT COUNT(id) AS count FROM Seat) AS num
ORDER BY
  id ASC
