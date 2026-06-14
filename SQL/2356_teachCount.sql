\c Leetcode

Create table If Not Exists Teacher (teacher_id int, subject_id int, dept_id int);

SELECT Teacher.teacher_id,COUNT(DISTINCT Teacher.subject_id) AS cnt
FROM Teacher
GROUP BY teacher_id;