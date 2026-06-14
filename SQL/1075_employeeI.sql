\c Leetcode

Create table If Not Exists Project (project_id int, employee_id int);
Create table If Not Exists Employee (employee_id int, name varchar(10), experience_years int);

SELECT Project.project_id,
ROUND(
    AVG(Employee.experience_years)::NUMERIC,
    2
)
AS average_years
FROM Employee INNER JOIN Project ON Project.employee_id = Employee.employee_id
GROUP BY project_id;