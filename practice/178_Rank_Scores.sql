/*
178. Rank Scores
Table: Scores

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id is the primary key for this table.
Each row of this table contains the score of a game. Score is a floating point value with two decimal places.
 

Write an SQL query to rank the scores. The ranking should be calculated according to the following rules:

The scores should be ranked from the highest to the lowest.
If there is a tie between two scores, both should have the same ranking.
After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.
Return the result table ordered by score in descending order.
*/
# Write your MySQL query statement below
SELECT
  s1.score,
  (SELECT  COUNT(DISTINCT s2.score) FROM Scores s2 WHERE s1.score <= s2.score) AS 'rank'
FROM
  Scores s1
ORDER BY
  s1.score DESC
