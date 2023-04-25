/*
2238. Number of Times a Driver Was a Passenger

Table: Rides

+--------------+------+
| Column Name  | Type |
+--------------+------+
| ride_id      | int  |
| driver_id    | int  |
| passenger_id | int  |
+--------------+------+
ride_id is the primary key for this table.
Each row of this table contains the ID of the driver and the ID of the passenger that rode in ride_id.
Note that driver_id != passenger_id.
 

Write an SQL query to report the ID of each driver and the number of times they were a passenger.

Return the result table in any order.


*/
# Write your MySQL query statement below
WITH A AS (SELECT DISTINCT
            driver_id
          FROM
            Rides)
SELECT
  a.driver_id,
  COUNT(r.passenger_id) AS cnt 
FROM
  A AS a
LEFT JOIN
  Rides r 
ON
  r.passenger_id = a.driver_id
GROUP BY
  driver_id

