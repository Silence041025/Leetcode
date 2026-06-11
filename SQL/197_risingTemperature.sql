\c Leetcode

Create table If Not Exists Weather (id int, recordDate date, temperature int);

SELECT W2.id FROM Weather W1 JOIN Weather W2
ON W1.temperature < W2.temperature
WHERE W2.recordDate - W1.recordDate = 1;