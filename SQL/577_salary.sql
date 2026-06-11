\c Leetcode

Create table If Not Exists Employee (empId int, name varchar(255), supervisor int, salary int);
Create table If Not Exists Bonus (empId int, bonus int);

SELECT name,Bonus.bonus
FROM Employee LEFT JOIN Bonus ON Employee.empId = Bonus.empId
WHERE Bonus.bonus < 1000 OR Bonus IS NULL;