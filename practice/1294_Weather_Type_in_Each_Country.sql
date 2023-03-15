/*
1294. Weather Type in Each Country
Table: Countries

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| country_id    | int     |
| country_name  | varchar |
+---------------+---------+
country_id is the primary key for this table.
Each row of this table contains the ID and the name of one country.
 

Table: Weather

+---------------+------+
| Column Name   | Type |
+---------------+------+
| country_id    | int  |
| weather_state | int  |
| day           | date |
+---------------+------+
(country_id, day) is the primary key for this table.
Each row of this table indicates the weather state in a country for one day.
 

Write an SQL query to find the type of weather in each country for November 2019.

The type of weather is:

Cold if the average weather_state is less than or equal 15,
Hot if the average weather_state is greater than or equal to 25, and
Warm otherwise.
*/
# Write your MySQL query statement below
/*SELECT 
  country_name,
  (CASE WHEN T.avg <= 15 THEN 'Cold'
    WHEN t.avg >= 25 THEN 'Hot'
    ELSE 'Warm'
  END) AS weather_type 
FROM 
  Countries,
  (SELECT 
    country_id,
    AVG(weather_state) AS avg
  FROM
    Weather 
  WHERE
    YEAR(Weather.day) = 2019
    AND MONTH(Weather.day) = 11
  GROUP BY
    country_id) AS T 
WHERE Countries.country_id = T.country_id*/
SELECT 
  country_name,
  CASE WHEN AVG(weather_state) <= 15 THEN 'Cold'
    WHEN AVG(weather_state) >= 25 THEN 'Hot'
    ELSE 'Warm'
  END AS weather_type
FROM 
  Countries c
JOIN Weather w
ON
  c.country_id = w.country_id
WHERE
  YEAR(w.day) = 2019 AND MONTH(w.day) = 11
GROUP BY
  country_name
