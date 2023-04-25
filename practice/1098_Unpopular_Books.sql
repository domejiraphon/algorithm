/*
1098. Unpopular Books
Table: Books

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| book_id        | int     |
| name           | varchar |
| available_from | date    |
+----------------+---------+
book_id is the primary key of this table.
 

Table: Orders

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| order_id       | int     |
| book_id        | int     |
| quantity       | int     |
| dispatch_date  | date    |
+----------------+---------+
order_id is the primary key of this table.
book_id is a foreign key to the Books table.
 

Write an SQL query that reports the books that have sold less than 10 copies in the last year, excluding books that have been available for less than one month from today. Assume today is 2019-06-23.

Return the result table in any order.


*/
# Write your MySQL query statement below
SELECT
  book_id,
  name
FROM 
  Books 
WHERE
  available_from < '2019-05-23' AND book_id NOT IN (SELECT
              book_id
            FROM
              Orders
            WHERE
              dispatch_date >= DATE('2018-06-23')
            GROUP BY
              book_id
            HAVING
              SUM(quantity) >= 10)

