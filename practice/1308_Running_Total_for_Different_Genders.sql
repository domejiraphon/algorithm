/*
1308. Running Total for Different Genders
Table: Scores

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| player_name   | varchar |
| gender        | varchar |
| day           | date    |
| score_points  | int     |
+---------------+---------+
(gender, day) is the primary key for this table.
A competition is held between the female team and the male team.
Each row of this table indicates that a player_name and with gender has scored score_point in someday.
Gender is 'F' if the player is in the female team and 'M' if the player is in the male team.
 

Write an SQL query to find the total score for each gender on each day.

Return the result table ordered by gender and day in ascending order.
*/
# Write your MySQL query statement below
SELECT
  s1.gender,
  s1.day,
  SUM(s2.score_points) AS total
FROM
  Scores s1
JOIN
  Scores s2
ON
  s1.day >= s2.day AND s1.gender = s2.gender
GROUP BY 
  gender,
  day
ORDER BY
  gender,
  day

