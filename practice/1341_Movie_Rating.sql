/*
1341. Movie Rating
Table: Movies

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| title         | varchar |
+---------------+---------+
movie_id is the primary key for this table.
title is the name of the movie.
 

Table: Users

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| user_id       | int     |
| name          | varchar |
+---------------+---------+
user_id is the primary key for this table.
 

Table: MovieRating

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| movie_id      | int     |
| user_id       | int     |
| rating        | int     |
| created_at    | date    |
+---------------+---------+
(movie_id, user_id) is the primary key for this table.
This table contains the rating of a movie by a user in their review.
created_at is the user's review date. 
 

Write an SQL query to:

Find the name of the user who has rated the greatest number of movies. In case of a tie, return the lexicographically smaller user name.
Find the movie name with the highest average rating in February 2020. In case of a tie, return the lexicographically smaller movie name.
*/

(SELECT 
  name AS results
FROM
  Users u
JOIN
  MovieRating m
ON
  u.user_id = m.user_id
GROUP BY
  u.user_id
ORDER BY
  COUNT(u.user_id) DESC,
  name ASC
LIMIT 1
)
UNION
(SELECT 
  m.title
FROM
  MovieRating mr
JOIN 
  Movies m
ON 
  m.movie_id = mr.movie_id
WHERE
  LEFT(created_at, 7) = '2020-02'
GROUP BY
  m.movie_id
ORDER BY 
  AVG(rating) DESC,
  m.title ASC
LIMIT 1
)
