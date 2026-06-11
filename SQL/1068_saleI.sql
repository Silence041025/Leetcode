\c Leetcode

Create table If Not Exists Sales (sale_id int, product_id int, year int, quantity int, price int);
Create table If Not Exists Product (product_id int, product_name varchar(10));

SELECT product_name,Sales.year,Sales.price
FROM Sales INNER JOIN Product ON Sales.product_id = Product.product_id;
