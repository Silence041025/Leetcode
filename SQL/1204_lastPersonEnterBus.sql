\c Leetcode

Create table If Not Exists Queue (person_id int, person_name varchar(30), weight int, turn int);

WITH
QueueWithTotal AS(
    SELECT Queue.person_id,Queue.person_name,Queue.weight,Queue.turn,
           SUM(Queue.weight) OVER(ORDER BY Queue.turn ASC) AS total
    FROM Queue
)
SELECT QueueWithTotal.person_name FROM QueueWithTotal
WHERE total <= 1000
ORDER BY turn DESC
LIMIT 1;