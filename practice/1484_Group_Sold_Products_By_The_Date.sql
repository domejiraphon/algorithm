/*
1484. Group Sold Products By The Date
Table Activities:

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| sell_date   | date    |
| product     | varchar |
+-------------+---------+
There is no primary key for this table, it may contain duplicates.
Each row of this table contains the product name and the date it was sold in a market.
 

Write an SQL query to find for each date the number of different products sold and their names.

The sold products names for each date should be sorted lexicographically.

Return the result table ordered by sell_date.

The query result format is in the following example.
*/
# Write your MySQL query statement below
SELECT sell_date,
  COUNT(sell_date) as 'num_sold',
  GROUP_CONCAT(distinct product ORDER BY product) AS 'products'
FROM 
  (SELECT DISTINCT sell_date,product FROM Activities) as Activities
GROUP BY sell_date;

