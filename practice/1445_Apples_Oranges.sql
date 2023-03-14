/*
1445. Apples & Oranges
Table: Sales

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| sale_date     | date    |
| fruit         | enum    | 
| sold_num      | int     | 
+---------------+---------+
(sale_date, fruit) is the primary key for this table.
This table contains the sales of "apples" and "oranges" sold each day.
 

Write an SQL query to report the difference between the number of apples and oranges sold each day.

Return the result table ordered by sale_date.
*/
# Write your MySQL query statement below
SELECT sale_date, 
  SUM(CASE
        WHEN fruit = 'apples' THEN sold_num
        ELSE -1 * sold_num
      END) AS diff
  FROM Sales
  GROUP BY sale_date;
