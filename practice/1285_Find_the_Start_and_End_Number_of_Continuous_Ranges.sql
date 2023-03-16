/*
1285. Find the Start and End Number of Continuous Ranges
Table: Logs

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| log_id        | int     |
+---------------+---------+
log_id is the primary key for this table.
Each row of this table contains the ID in a log Table.
 

Write an SQL query to find the start and end number of continuous ranges in the table Logs.

Return the result table ordered by start_id.
*/
# Write your MySQL query statement below
SELECT
  MIN(T.log_id) AS start_id,
  MAX(T.log_id) AS end_id
FROM 
  (SELECT 
    log_id,
    ROW_NUMBER() OVER(ORDER BY log_id) AS rownumber
  FROM
    Logs) AS T
GROUP BY
  T.log_id - T.rownumber
ORDER BY 
  start_id

