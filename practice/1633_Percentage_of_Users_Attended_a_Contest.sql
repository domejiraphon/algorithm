/*
1633. Percentage of Users Attended a Contest
Table: Users

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| user_name   | varchar |
+-------------+---------+
user_id is the primary key for this table.
Each row of this table contains the name and the id of a user.
 

Table: Register

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| contest_id  | int     |
| user_id     | int     |
+-------------+---------+
(contest_id, user_id) is the primary key for this table.
Each row of this table contains the id of a user and the contest they registered into.
 

Write an SQL query to find the percentage of the users registered in each contest rounded to two decimals.

Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.


*/
# Write your MySQL query statement below
SELECT contest_id,
  ROUND(COUNT(r.user_id) /(SELECT COUNT(user_id) FROM Users) * 100, 2)
  AS percentage
  FROM Register r 
  GROUP BY contest_id
  ORDER BY percentage DESC, contest_id ASC
