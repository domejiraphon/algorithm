/*
1369. Get the Second Most Recent Activity
Table: UserActivity

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| username      | varchar |
| activity      | varchar |
| startDate     | Date    |
| endDate       | Date    |
+---------------+---------+
There is no primary key for this table. It may contain duplicates.
This table contains information about the activity performed by each user in a period of time.
A person with username performed an activity from startDate to endDate.
 

Write an SQL query to show the second most recent activity of each user.

If the user only has one activity, return that one. A user cannot perform more than one activity at the same time.
*/
# Write your MySQL query statement below
WITH T AS (
        SELECT
          username,
          activity,
          startDate,
          endDate,
          COUNT(*) OVER(PARTITION BY username) AS cnt,
          RANK() OVER(PARTITION BY username ORDER BY endDate DESC) AS 'rank'
        FROM
          UserActivity
)
SELECT
  username,
  activity,
  startDate,
  endDate
FROM
  T
WHERE
  (cnt >= 2 AND T.rank = 2) OR (cnt = 1 AND T.rank =1 )
 
    
