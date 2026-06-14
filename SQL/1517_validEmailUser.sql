\c Leetcode

Create table If Not Exists Users (user_id int, name varchar(30), mail varchar(50));

SELECT user_id, name, mail
FROM Users
WHERE mail ~ '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$';