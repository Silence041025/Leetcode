\c Leetcode

Create table If Not Exists Users (user_id int, user_name varchar(20));
Create table If Not Exists Register (contest_id int, user_id int);

SELECT Register.contest_id,
ROUND(
    COUNT(Register.user_id)*100::NUMERIC / (SELECT COUNT(*) FROM Users),
    2
)
AS percentage
FROM Register
GROUP BY contest_id
ORDER BY percentage DESC,contest_id ASC;

