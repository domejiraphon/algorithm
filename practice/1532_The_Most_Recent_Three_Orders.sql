/*
1532. The Most Recent Three Orders
Table: Customers

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
+---------------+---------+
customer_id is the primary key for this table.
This table contains information about customers.
 

Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| cost          | int     |
+---------------+---------+
order_id is the primary key for this table.
This table contains information about the orders made by customer_id.
Each customer has one order per day.
 

Write an SQL query to find the most recent three orders of each user. If a user ordered less than three orders, return all of their orders.

Return the result table ordered by customer_name in ascending order and in case of a tie by the customer_id in ascending order. If there is still a tie, order them by order_date in descending order.
*/
# Write your MySQL query statement below
WITH T AS (SELECT
            name AS customer_name,
            c.customer_id,
            order_id,
            order_date,
            RANK() OVER(PARTITION BY c.customer_id ORDER BY order_date DESC) AS 'rank'
          FROM
            Customers c
          JOIN
            Orders o
          ON
            c.customer_id = o.customer_id)
SELECT 
  customer_name,
  customer_id,
  order_id,
  order_date
FROM 
  T
WHERE
  T.rank <= 3
ORDER BY 
  customer_name ASC,
  customer_id ASC,
  order_date DESC


