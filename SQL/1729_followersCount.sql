\c Leetcode

Create table If Not Exists Followers(user_id int, follower_id int);

SELECT Followers.user_id,COUNT(Followers.follower_id) AS followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id ASC;