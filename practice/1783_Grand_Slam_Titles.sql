/*
1783. Grand Slam Titles
Table: Players

+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| player_id      | int     |
| player_name    | varchar |
+----------------+---------+
player_id is the primary key for this table.
Each row in this table contains the name and the ID of a tennis player.
 

Table: Championships

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| year          | int     |
| Wimbledon     | int     |
| Fr_open       | int     |
| US_open       | int     |
| Au_open       | int     |
+---------------+---------+
year is the primary key for this table.
Each row of this table contains the IDs of the players who won one each tennis tournament of the grand slam.
 

Write an SQL query to report the number of grand slam tournaments won by each player. Do not include the players who did not win any tournament.
*/
# Write your MySQL query statement below
SELECT 
  player_id,
  player_name,
  SUM(c.Wimbledon = p.player_id) + SUM(c.Fr_open = p.player_id) +
  SUM(c.US_open = p.player_id) + SUM(c.AU_open = p.player_id)
  AS grand_slams_count
FROM
  Players p
JOIN
  Championships c
ON
  c.Wimbledon = p.player_id OR p.player_id = c.Fr_open OR p.player_id = c.US_open OR p.player_id = c.AU_open
GROUP BY
  player_id
