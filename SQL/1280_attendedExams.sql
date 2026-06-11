\c Leetcode

Create table If Not Exists Students (student_id int, student_name varchar(20));
Create table If Not Exists Subjects (subject_name varchar(20));
Create table If Not Exists Examinations (student_id int, subject_name varchar(20));

SELECT Students.student_id,Students.student_name,Subjects.subject_name,
COUNT(Examinations.subject_name) AS attended_exams
FROM Students CROSS JOIN Subjects
LEFT JOIN Examinations ON Subjects.subject_name = Examinations.subject_name
AND Students.student_id = Examinations.student_id
GROUP BY Students.student_id,student_name,Subjects.subject_name
ORDER BY student_id,subject_name;