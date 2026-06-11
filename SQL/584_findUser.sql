\c Leetcode

Create table If Not Exists Customer (id int, name varchar(25), referee_id int);

SELECT name FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL;