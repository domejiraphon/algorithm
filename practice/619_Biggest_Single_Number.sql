/*
619. Biggest Single Number
Table: MyNumbers

+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
There is no primary key for this table. It may contain duplicates.
Each row of this table contains an integer.
 

A single number is a number that appeared only once in the MyNumbers table.

Write an SQL query to report the largest single number. If there is no single number, report null.
*/
SELECT
    MAX(T.num) AS num
FROM
  (SELECT
        num
    FROM
        MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1) AS T;
