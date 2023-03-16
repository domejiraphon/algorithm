/*
1613. Find the Missing IDs
Table: Customers

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| customer_name | varchar |
+---------------+---------+
customer_id is the primary key for this table.
Each row of this table contains the name and the id customer.
 

Write an SQL query to find the missing customer IDs. The missing IDs are ones that are not in the Customers table but are in the range between 1 and the maximum customer_id present in the table.

Notice that the maximum customer_id will not exceed 100.

Return the result table ordered by ids in ascending order.
*/
# Write your MySQL query statement below
WITH RECURSIVE
  cte AS (
    SELECT 1 AS n
    UNION ALL
    SELECT n + 1 FROM cte WHERE n < (SELECT MAX(customer_id) FROM Customers)
  )
SELECT 
  cte.n AS ids
FROM 
  cte
WHERE
  cte.n NOT IN (SELECT DISTINCT customer_id FROM Customers)


