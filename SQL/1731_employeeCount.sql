\c Leetcode

Create table If Not Exists Employees(employee_id int, name varchar(20), reports_to int, age int);

SELECT
E2.employee_id,
E2.name,
COUNT(E1.reports_to) AS reports_count,
ROUND(
    AVG(E1.age)::NUMERIC,
    0
) AS average_age
FROM Employees E1 INNER JOIN Employees E2 ON E1.reports_to = E2.employee_id
GROUP BY E2.employee_id, E2.name
ORDER BY employee_id;