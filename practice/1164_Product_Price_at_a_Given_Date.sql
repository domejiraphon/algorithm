/*
1164. Product Price at a Given Date
Table: Products

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| new_price     | int     |
| change_date   | date    |
+---------------+---------+
(product_id, change_date) is the primary key of this table.
Each row of this table indicates that the price of some product was changed to a new price at some date.
 

Write an SQL query to find the prices of all products on 2019-08-16. Assume the price of all products before any change is 10.
*/
# Write your MySQL query statement below
SELECT
  product_id,
  10 AS price
FROM 
  Products
GROUP BY
  product_id
HAVING
  MIN(change_date) > '2019-08-16'
UNION ALL
SELECT
  product_id,
  new_price AS price 
FROM
  Products
WHERE (
  product_id, change_date
  ) IN (
    SELECT 
      product_id,
      MAX(change_date)
    FROM 
      Products
    WHERE
      change_date <= '2019-08-16'
    GROUP BY
      product_id
  )

