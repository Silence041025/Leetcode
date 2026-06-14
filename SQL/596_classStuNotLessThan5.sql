\c Leetcode

Create table If Not Exists Courses (student varchar(255), class varchar(255));

SELECT Courses.class
FROM Courses
GROUP BY class
HAVING COUNT(student)>=5;