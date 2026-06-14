\c Leetcode

Create table If Not Exists Seat (id int, student varchar(255));

SELECT
CASE
    WHEN id % 2 = 1 AND id = (SELECT COUNT(*) FROM Seat)
    THEN id
    WHEN id % 2 = 1
    THEN id + 1
    ELSE id - 1
END
AS id,
Seat.student
FROM Seat
ORDER BY id ASC;