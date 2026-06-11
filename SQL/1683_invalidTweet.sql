\c Leetcode

Create table If Not Exists Tweets(tweet_id int, content varchar(50));

SELECT Tweets.tweet_id FROM Tweets
WHERE length(content) > 15;

