/*
1141. User Activity for the Past 30 Days I
Table: Activity

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| session_id    | int     |
| activity_date | date    |
| activity_type | enum    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
The activity_type column is an ENUM of type ('open_session', 'end_session', 'scroll_down', 'send_message').
The table shows the user activities for a social media website. 
Note that each session belongs to exactly one user.
 

Write an SQL query to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. A user was active on someday if they made at least one activity on that day.

Return the result table in any order.
*/
# Write your MySQL query statement below
SELECT T.activity_date AS 'day',
  count(T.user_id) AS 'active_users'
  FROM (SELECT DISTINCT user_id, activity_date FROM Activity)
AS T WHERE T.activity_date > "2019-06-27" AND T.activity_date <= "2019-07-27"
GROUP BY activity_date;

