/*
1264. Page Recommendations
Table: Friendship

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user1_id      | int     |
| user2_id      | int     |
+---------------+---------+
(user1_id, user2_id) is the primary key for this table.
Each row of this table indicates that there is a friendship relation between user1_id and user2_id.
 

Table: Likes

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| page_id     | int     |
+-------------+---------+
(user_id, page_id) is the primary key for this table.
Each row of this table indicates that user_id likes page_id.
 

Write an SQL query to recommend pages to the user with user_id = 1 using the pages that your friends liked. It should not recommend pages you already liked.

Return result table in any order without duplicates.
*/
# Write your MySQL query statement below
/*SELECT T.page_id AS recommended_page 
FROM ((SELECT DISTINCT page_id 
  FROM Friendship, Likes
  WHERE user1_id = 1 AND user2_id = user_id)
  UNION
  (SELECT DISTINCT page_id 
  FROM Friendship, Likes
  WHERE user2_id = 1 AND user1_id = user_id))
AS T
WHERE T.page_id NOT IN (SELECT DISTINCT page_id 
    FROM Friendship, Likes
    WHERE user_id = 1)*/
SELECT DISTINCT Likes.page_id AS recommended_page
FROM (SELECT DISTINCT
        (CASE WHEN user1_id = 1 THEN user2_id
        ELSE user1_id
        END) AS user_id
      FROM Friendship 
      WHERE user1_id = 1 or user2_id = 1) AS T
JOIN Likes 
ON T.user_id = Likes.user_id
WHERE page_id NOT IN (SELECT page_id 
    FROM Likes
    WHERE user_id = 1)



