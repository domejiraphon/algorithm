/*
1126. Active Businesses
Table: Events

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| business_id   | int     |
| event_type    | varchar |
| occurences    | int     | 
+---------------+---------+
(business_id, event_type) is the primary key of this table.
Each row in the table logs the info that an event of some type occurred at some business for a number of times.
 

The average activity for a particular event_type is the average occurences across all companies that have this event.

An active business is a business that has more than one event_type such that their occurences is strictly greater than the average activity for that event.

Write an SQL query to find all active businesses.
*/
# Write your MySQL query statement below
SELECT
  business_id                                     
FROM 
  (SELECT 
    event_type,
    AVG(occurences) AS avg
  FROM 
    Events 
  GROUP BY
    event_type) AS T
JOIN 
  Events e1 
ON
  T.event_type = e1.event_type
WHERE 
  e1.occurences > T.avg 
GROUP BY 
  business_id
HAVING 
  COUNT(*) > 1
