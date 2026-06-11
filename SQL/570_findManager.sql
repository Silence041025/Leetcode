\c Leetcode
Create table If Not Exists Employee (id int, name varchar(255), department varchar(255), managerId int);

SELECT E2.name AS name
FROM Employee E1 INNER JOIN Employee E2 ON E1.managerId = E2.id
GROUP BY E2.id,E2.name
HAVING COUNT(E2.id) >= 5;