\c Leetcode

Create table If Not Exists Delivery (delivery_id int, customer_id int, order_date date, customer_pref_delivery_date date);

WITH Delivery_with_row_number
AS(
    SELECT Delivery.delivery_id,Delivery.customer_id,
           Delivery.order_date,Delivery.customer_pref_delivery_date,
    ROW_NUMBER() OVER(
        PARTITION BY Delivery.customer_id
        ORDER BY Delivery.order_date ASC
    ) AS row_number
    FROM Delivery
),
First_orders AS(
    SELECT Delivery_with_row_number.delivery_id,
           Delivery_with_row_number.customer_id,
           Delivery_with_row_number.order_date,
           Delivery_with_row_number.customer_pref_delivery_date
    FROM Delivery_with_row_number WHERE row_number = 1
)
SELECT
ROUND(
    COUNT(CASE WHEN order_date = customer_pref_delivery_date THEN 1 END)::NUMERIC*100/
    (SELECT COUNT(*) FROM First_orders),
    2
)
AS immediate_percentage
FROM First_orders;