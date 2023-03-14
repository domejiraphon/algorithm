/*
1398. Customers Who Bought Products A and B but Not C
Table: Customers

+---------------------+---------+
| Column Name         | Type    |
+---------------------+---------+
| customer_id         | int     |
| customer_name       | varchar |
+---------------------+---------+
customer_id is the primary key for this table.
customer_name is the name of the customer.
 

Table: Orders

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| customer_id   | int     |
| product_name  | varchar |
+---------------+---------+
order_id is the primary key for this table.
customer_id is the id of the customer who bought the product "product_name".
 

Write an SQL query to report the customer_id and customer_name of customers who bought products "A", "B" but did not buy the product "C" since we want to recommend them to purchase this product.

Return the result table ordered by customer_id.
*/
# Write your MySQL query statement below
SELECT c.customer_id, c.customer_name
FROM Customers c, Orders o
WHERE c.customer_id = o.customer_id
GROUP BY c.customer_id
HAVING SUM(o.product_name = 'A') >= 1 AND 
       SUM(o.product_name = 'B') >= 1 AND
       SUM(o.product_name = 'C') = 0
