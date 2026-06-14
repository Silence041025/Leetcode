\c Leetcode

Create table If Not Exists Prices (product_id int, start_date date, end_date date, price int);
Create table If Not Exists UnitsSold (product_id int, purchase_date date, units int);

SELECT Prices.product_id,
ROUND(
    CASE
        WHEN SUM(units) IS NULL
        THEN 0
        ELSE
        SUM(Prices.price*UnitsSold.units)::NUMERIC / SUM(UnitsSold.units)
    END,
    2
)
AS average_price
FROM Prices LEFT JOIN UnitsSold ON Prices.product_id = UnitsSold.product_id
AND purchase_date >= start_date
AND purchase_date <= end_date
GROUP BY Prices.product_id;
