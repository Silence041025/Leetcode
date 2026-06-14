\c Leetcode

Create table If Not Exists Product (product_id int, product_name varchar(10), unit_price int);
Create table If Not Exists Sales (seller_id int, product_id int, buyer_id int, sale_date date, quantity int, price int);

SELECT Sales.product_id,Product.product_name
FROM Product INNER JOIN Sales ON Sales.product_id = Product.product_id
GROUP BY Sales.product_id,product_name
HAVING MIN(sale_date) >= '2019-01-01' AND
       MAX(sale_date) < '2019-04-01';
