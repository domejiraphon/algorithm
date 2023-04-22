/*
2020. Number of Accounts That Did Not Stream
Table: Subscriptions

+-------------+------+
| Column Name | Type |
+-------------+------+
| account_id  | int  |
| start_date  | date |
| end_date    | date |
+-------------+------+
account_id is the primary key column for this table.
Each row of this table indicates the start and end dates of an account's subscription.
Note that always start_date < end_date.
 

Table: Streams

+-------------+------+
| Column Name | Type |
+-------------+------+
| session_id  | int  |
| account_id  | int  |
| stream_date | date |
+-------------+------+
session_id is the primary key column for this table.
account_id is a foreign key from the Subscriptions table.
Each row of this table contains information about the account and the date associated with a stream session.
 

Write an SQL query to report the number of accounts that bought a subscription in 2021 but did not have any stream session.

The query result format is in the following example.


*/
# Write your MySQL query statement below
SELECT
  COUNT(sub.account_id) AS accounts_count
FROM
  Subscriptions AS sub
JOIN
  Streams AS st
ON
  sub.account_id = st.account_id
WHERE
  year(sub.start_date) <= 2021 AND year(sub.end_date) >= 2021 AND
  year(st.stream_date) != 2021
