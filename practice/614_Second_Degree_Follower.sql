/*
614. Second Degree Follower
Table: Follow

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| followee    | varchar |
| follower    | varchar |
+-------------+---------+
(followee, follower) is the primary key column for this table.
Each row of this table indicates that the user follower follows the user followee on a social network.
There will not be a user following themself.
 

A second-degree follower is a user who:

follows at least one user, and
is followed by at least one user.
Write an SQL query to report the second-degree users and the number of their followers.

Return the result table ordered by follower in alphabetical order.
*/
# Write your MySQL query statement below
WITH A AS (SELECT
            follower,
            COUNT(follower) AS is_followed
          FROM
            Follow 
          GROUP BY
            follower),
    B AS (SELECT
            followee,
            COUNT(followee) AS num
          FROM
            Follow
          GROUP BY
            followee)
SELECT
  follower,
  num
FROM
  A, B
WHERE 
  A.follower = B.followee AND num >= 1 AND is_followed >= 1
ORDER BY
  follower ASC
