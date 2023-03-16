/*
1951. All the Pairs With the Maximum Number of Common Followers
Table: Relations

+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) is the primary key for this table.
Each row of this table indicates that the user with ID follower_id is following the user with ID user_id.
 

Write an SQL query to find all the pairs of users with the maximum number of common followers. In other words, if the maximum number of common followers between any two users is maxCommon, then you have to return all pairs of users that have maxCommon common followers.

The result table should contain the pairs user1_id and user2_id where user1_id < user2_id.
*/
# Write your MySQL query statement below
WITH T AS (SELECT
              u1.user_id AS user1_id,
              u2.user_id As user2_id,
              COUNT(u1.follower_id) AS num
            FROM
              Relations u1
            JOIN
              Relations u2
            ON
              u1.user_id < u2.user_id 
              AND u1.follower_id = u2.follower_id 
            GROUP BY
              user1_id, user2_id)
SELECT
  user1_id,
  user2_id
FROM 
  T
WHERE
  num = (SELECT MAX(num) FROM T)



