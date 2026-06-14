\c Leetcode

Create table If Not Exists Person (Id int, Email varchar(255));


DELETE FROM
Person
WHERE id NOT IN(
    SELECT MIN(id) FROM Person
    GROUP BY Email
);


