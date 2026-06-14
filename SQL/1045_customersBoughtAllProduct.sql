\c Leetcode

Create table If Not Exists Customer (customer_id int, product_key int);
Create table Product (product_key int);

SELECT Customer.customer_id
FROM Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);