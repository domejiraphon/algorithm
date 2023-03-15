/*
180. Consecutive Numbers
Table: Logs

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
id is the primary key for this table.
id is an autoincrement column.
 

Write an SQL query to find all numbers that appear at least three times consecutively.
*/
# Write your MySQL query statement below
SELECT DISTINCT
  l1.num AS ConsecutiveNums
FROM 
  Logs l1
JOIN
  Logs l2
ON
  l1.id + 1 = l2.id AND l1.num = l2.num
JOIN 
  Logs l3
ON 
  l2.id + 1 = l3.id AND l2.num = l3.num

