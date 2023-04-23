/*
2112. The Airport With the Most Traffic
Table: Flights

+-------------------+------+
| Column Name       | Type |
+-------------------+------+
| departure_airport | int  |
| arrival_airport   | int  |
| flights_count     | int  |
+-------------------+------+
(departure_airport, arrival_airport) is the primary key column for this table.
Each row of this table indicates that there were flights_count flights that departed from departure_airport and arrived at arrival_airport.
 

Write an SQL query to report the ID of the airport with the most traffic. The airport with the most traffic is the airport that has the largest total number of flights that either departed from or arrived at the airport. If there is more than one airport with the most traffic, report them all.

Return the result table in any order.
*/
# Write your MySQL query statement below
WITH T AS (SELECT
              departure_airport AS airport_id,
              flights_count
            FROM
              Flights
            UNION ALL
            SELECT
              arrival_airport AS airport_id,
              flights_count
            FROM
              Flights),
    B AS  (SELECT
            T.airport_id,
            SUM(T.flights_count) AS num
          FROM
            T
          GROUP BY 
            airport_id)
SELECT
  airport_id
FROM 
  B
WHERE
  B.num IN (SELECT MAX(num) FROM B)





