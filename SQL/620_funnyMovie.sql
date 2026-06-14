\c Leetcode

CREATE TABLE IF NOT EXISTS cinema (
      id INTEGER,
      movie VARCHAR(255),
      description VARCHAR(255),
      rating DECIMAL(3, 1)
);

SELECT id,cinema.movie,cinema.description,cinema.rating
FROM cinema
WHERE description <> 'boring'
AND id % 2 = 1
ORDER BY rating DESC;
