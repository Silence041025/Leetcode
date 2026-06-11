\c Leetcode

CREATE TABLE IF NOT EXISTS Products (
    product_id INT,
    low_fats VARCHAR(1) CHECK (low_fats IN ('Y', 'N')),
    recyclable VARCHAR(1) CHECK (recyclable IN ('Y', 'N'))
);

SELECT Products.product_id FROM Products
WHERE recyclable = 'Y' AND low_fats = 'Y';

