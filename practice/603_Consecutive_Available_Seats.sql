/*
603. Consecutive Available Seats
Table: Cinema

+-------------+------+
| Column Name | Type |
+-------------+------+
| seat_id     | int  |
| free        | bool |
+-------------+------+
seat_id is an auto-increment primary key column for this table.
Each row of this table indicates whether the ith seat is free or not. 1 means free while 0 means occupied.
 

Write an SQL query to report all the consecutive available seats in the cinema.

Return the result table ordered by seat_id in ascending order.

The test cases are generated so that more than two seats are consecutively available.
*/
# Write your MySQL query statement below
SELECT DISTINCT
  s1.seat_id
FROM
  Cinema s1
JOIN 
  Cinema s2
ON 
  s1.seat_id + 1 = s2.seat_id OR s1.seat_id - 1 = s2.seat_id
WHERE
  s1.free = 1 AND s2.free = 1
