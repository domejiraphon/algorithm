# Write your MySQL query statement below
/*
586. Customer Placing the Largest Number of Orders
Table: Orders

+-----------------+----------+
| Column Name     | Type     |
+-----------------+----------+
| order_number    | int      |
| customer_number | int      |
+-----------------+----------+
order_number is the primary key for this table.
This table contains information about the order ID and the customer ID.
 

Write an SQL query to find the customer_number for the customer who has placed the largest number of orders.

The test cases are generated so that exactly one customer will have placed more orders than any other customer.
*/
/*WITH T AS (SELECT customer_number, COUNT(customer_number) AS num
  FROM Orders GROUP BY customer_number)
SELECT T.customer_number FROM T WHERE (T.num = (SELECT max(T.num) FROM T));*/
SELECT customer_number FROM Orders GROUP BY customer_number ORDER BY COUNT(*) DESC LIMIT 1;
