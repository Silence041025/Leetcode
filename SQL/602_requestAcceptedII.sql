\c Leetcode

Create table If Not Exists RequestAccepted (requester_id int not null, accepter_id int null, accept_date date null);

WITH
combine AS(
    (
        SELECT RequestAccepted.requester_id AS id
        FROM RequestAccepted
    )
    UNION ALL
    (
        SELECT RequestAccepted.accepter_id AS id
        FROM RequestAccepted
    )
)
SELECT id,COUNT(id) AS num
FROM combine
GROUP BY id
ORDER BY COUNT(id) DESC
LIMIT 1;
