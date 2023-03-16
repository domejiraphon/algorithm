/*
1949. Strong Friendship
Table: Friendship

+-------------+------+
| Column Name | Type |
+-------------+------+
| user1_id    | int  |
| user2_id    | int  |
+-------------+------+
(user1_id, user2_id) is the primary key for this table.
Each row of this table indicates that the users user1_id and user2_id are friends.
Note that user1_id < user2_id.
 

A friendship between a pair of friends x and y is strong if x and y have at least three common friends.

Write an SQL query to find all the strong friendships.

Note that the result table should not contain duplicates with user1_id < user2_id.

Return the result table in any order.
*/

# Write your MySQL query statement below
WITH T AS (SELECT 
            user1_id,
            user2_id
          FROM
            Friendship
          UNION ALL
          SELECT
            user2_id,
            user1_id
          FROM
            Friendship)
SELECT 
  u1.user1_id,
  u2.user1_id AS 'user2_id'
  ,count(*) as common_friend 
FROM 
  T u1
JOIN
  T u2 
ON 
  u1.user1_id < u2.user1_id AND u1.user2_id = u2.user2_id
WHERE 
  (u1.user1_id, u2.user1_id) IN (SELECT * FROM friendship)
GROUP BY
  user1_id,
  user2_id
having count(*)>=3
