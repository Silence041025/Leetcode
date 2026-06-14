\c Leetcode

Create table If Not Exists Products (product_id int, product_name varchar(40), product_category varchar(40));
Create table If Not Exists Orders (product_id int, order_date date, unit int);

SELECT product_name,SUM(unit) AS unit
FROM Orders INNER JOIN Products ON Orders.product_id = Products.product_id
WHERE order_date >= '2020-02-01' AND order_date < '2020-03-01'
GROUP BY product_name
HAVING SUM(unit) >= 100;
