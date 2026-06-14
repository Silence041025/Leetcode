\c Leetcode

Create table If Not Exists Products (product_id int, new_price int, change_date date);

WITH ProductDateBefore816
AS(
    SELECT Products.product_id,Products.new_price,Products.change_date,
    ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC)
    AS row_number
    FROM Products
    WHERE change_date <= '2019-08-16'
)
SELECT
DISTINCT Products.product_id,
CASE
    WHEN ProductDateBefore816.product_id IS NULL
    THEN 10
    ELSE ProductDateBefore816.new_price
END AS price
FROM Products LEFT JOIN ProductDateBefore816
ON ProductDateBefore816.product_id = Products.product_id
AND row_number = 1;