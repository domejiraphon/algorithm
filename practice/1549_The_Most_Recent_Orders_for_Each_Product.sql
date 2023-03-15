/*
1549. The Most Recent Orders for Each Product
Table: Customers

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
+---------------+---------+
customer_id is the primary key for this table.
This table contains information about the customers.
 

Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| product_id    | int     |
+---------------+---------+
order_id is the primary key for this table.
This table contains information about the orders made by customer_id.
There will be no product ordered by the same user more than once in one day.
 

Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| price         | int     |
+---------------+---------+
product_id is the primary key for this table.
This table contains information about the Products.
 

Write an SQL query to find the most recent order(s) of each product.

Return the result table ordered by product_name in ascending order and in case of a tie by the product_id in ascending order. If there still a tie, order them by order_id in ascending order.
*/
# Write your MySQL query statement below
SELECT 
  p.product_name,
  p.product_id,
  o.order_id,
  o.order_date
FROM
  Products p
JOIN
  Orders o
ON
  p.product_id = o.product_id
WHERE
  (p.product_id, o.order_date) IN 
    (SELECT product_id, MAX(order_date) FROM Orders 
      GROUP BY product_id)
ORDER BY 
  p.product_name ASC,
  p.product_id ASC,
  o.order_id ASC
