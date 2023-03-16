/*
1831. Maximum Transaction Each Day
Table: Transactions

+----------------+----------+
| Column Name    | Type     |
+----------------+----------+
| transaction_id | int      |
| day            | datetime |
| amount         | int      |
+----------------+----------+
transaction_id is the primary key for this table.
Each row contains information about one transaction.
 

Write an SQL query to report the IDs of the transactions with the maximum amount on their respective day. If in one day there are multiple such transactions, return all of them.

Return the result table ordered by transaction_id in ascending order.
*/
# Write your MySQL query statement below
WITH T AS (SELECT
              LEFT(day, 10) AS each_day,
              MAX(amount) AS 'max'
            FROM
              Transactions
            GROUP BY
              LEFT(day, 10))
SELECT
  t1.transaction_id
FROM
  Transactions t1
JOIN
  T 
ON
  LEFT(t1.day, 10) = T.each_day 
WHERE
  t1.amount = T.max
ORDER BY
  t1.transaction_id

