\c Leetcode
Create table If Not Exists Employees (employee_id int, name varchar(20), manager_id int, salary int);

SELECT Employees.employee_id
FROM Employees
WHERE manager_id NOT IN(
    SELECT employee_id FROM Employees
)
AND salary < 30000
ORDER BY employee_id ASC;