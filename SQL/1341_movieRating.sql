\c Leetcode

Create table If Not Exists Movies (movie_id int, title varchar(30));
Create table If Not Exists Users (user_id int, name varchar(30));
Create table If Not Exists MovieRating (movie_id int, user_id int, rating int, created_at date);

(
    SELECT name AS results
    FROM MovieRating INNER JOIN Users ON Users.user_id = MovieRating.user_id
    GROUP BY Users.user_id,name
    ORDER BY COUNT(Users.user_id) DESC,name
    LIMIT 1
)
UNION ALL
(
    SELECT Movies.title AS results
    FROM Movies INNER JOIN MovieRating ON Movies.movie_id = MovieRating.movie_id
    WHERE created_at >= '2020-02-01' AND created_at < '2020-03-01'
    GROUP BY Movies.movie_id,title
    ORDER BY AVG(rating) DESC,title
    LIMIT 1
)
