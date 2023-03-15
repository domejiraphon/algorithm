/*
1321. Restaurant Growth
Table: Customer

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
| visited_on    | date    |
| amount        | int     |
+---------------+---------+
(customer_id, visited_on) is the primary key for this table.
This table contains data about customer transactions in a restaurant.
visited_on is the date on which the customer with ID (customer_id) has visited the restaurant.
amount is the total paid by a customer.
 

You are the restaurant owner and you want to analyze a possible expansion (there will be at least one customer every day).

Write an SQL query to compute the moving average of how much the customer paid in a seven days window (i.e., current day + 6 days before). average_amount should be rounded to two decimal places.

Return result table ordered by visited_on in ascending order.
*/
# Write your MySQL query statement below
SELECT 
  v1.visited_on,
  SUM(v2.day_sum) AS amount,
  ROUND(AVG(v2.day_sum), 2) AS average_amount
FROM
  (SELECT visited_on, SUM(amount) AS day_sum FROM Customer GROUP BY visited_on) v1 
JOIN
  (SELECT visited_on, SUM(amount) AS day_sum FROM Customer GROUP BY visited_on) v2 
ON 
  DATEDIFF(v1.visited_on, v2.visited_on) BETWEEN 0 AND 6
GROUP BY
  v1.visited_on
HAVING
  COUNT(v2.visited_on) = 7
ORDER BY
  v1.visited_on ASC

