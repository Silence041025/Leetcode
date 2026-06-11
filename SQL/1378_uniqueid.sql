\c Leetcode

Create table If Not Exists Employees (id int, name varchar(20));
Create table If Not Exists EmployeeUNI (id int, unique_id int);

SELECT EmployeeUNI.unique_id,Employees.name FROM
EmployeeUNI RIGHT JOIN Employees ON Employees.id = EmployeeUNI.id;