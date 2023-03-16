/*
1596. The Most Frequently Ordered Products for Each Customer
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
No customer will order the same product more than once in a single day.
 

Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| price         | int     |
+---------------+---------+
product_id is the primary key for this table.
This table contains information about the products.
 

Write an SQL query to find the most frequently ordered product(s) for each customer.

The result table should have the product_id and product_name for each customer_id who ordered at least one order.

Return the result table in any order.
*/
# Write your MySQL query statement below
WITH T AS (SELECT
        customer_id,
        product_id,
        COUNT(order_id) AS num
      FROM
        Orders 
      GROUP BY
        customer_id,
        product_id)
SELECT 
  customer_id,
  p.product_id,
  p.product_name
FROM 
  T 
JOIN
  Products p
ON
  p.product_id = T.product_id
WHERE
  (customer_id, num) IN (SELECT customer_id, MAX(num) FROM T GROUP BY customer_id)



