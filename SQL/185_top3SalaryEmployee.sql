\c Leetcode

Create table If Not Exists Employee (id int, name varchar(255), salary int, departmentId int);
Create table If Not Exists Department (id int, name varchar(255));

WITH
windowed AS(
    SELECT Employee.name AS Employee,Department.name AS Department,salary AS Salary,
    DENSE_RANK() OVER(PARTITION BY Department ORDER BY salary DESC) AS rk
    FROM Employee INNER JOIN Department ON departmentId = Department.id
)
SELECT Department,Employee,Salary
FROM windowed
WHERE rk <= 3
ORDER BY rk ASC;