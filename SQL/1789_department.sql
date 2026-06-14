\c Leetcode

CREATE TABLE IF NOT EXISTS Employee (
    employee_id INT,
    department_id INT,
    primary_flag VARCHAR(1) CHECK (primary_flag IN ('Y', 'N'))
);

SELECT Employee.employee_id,Employee.department_id
FROM Employee WHERE primary_flag = 'Y' OR employee_id IN(
    SELECT employee_id FROM Employee
    GROUP BY employee_id
    HAVING COUNT(department_id) = 1
);