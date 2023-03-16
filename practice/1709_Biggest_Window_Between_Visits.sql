/*
1709. Biggest Window Between Visits
Table: UserVisits

+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| visit_date  | date |
+-------------+------+
This table does not have a primary key.
This table contains logs of the dates that users visited a certain retailer.
 

Assume today's date is '2021-1-1'.

Write an SQL query that will, for each user_id, find out the largest window of days between each visit and the one right after it (or today if you are considering the last visit).

Return the result table ordered by user_id.
*/
SELECT user_id, MAX(diff) AS biggest_window
FROM
(
	SELECT user_id, 
	   DATEDIFF(LEAD(visit_date, 1, '2021-01-01') OVER (PARTITION BY user_id ORDER BY visit_date), visit_date) AS diff
	FROM userVisits
) a
GROUP BY user_id
ORDER BY user_id
