\c Leetcode

Create table If Not Exists MyNumbers (num int);

SELECT MAX(MyNumbersCount1.num) AS num
FROM(
    SELECT MyNumbers.num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
)AS MyNumbersCount1;
