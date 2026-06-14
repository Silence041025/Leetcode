\c Leetcode
Create table If Not Exists Customer (customer_id int, name varchar(20), visited_on date, amount int);

WITH
daily_total AS(
    SELECT Customer.visited_on,
    SUM(Customer.amount) AS sum_amount
    FROM Customer
    GROUP BY visited_on
),
windowed AS(
    SELECT daily_total.visited_on,
    SUM(daily_total.sum_amount) OVER(
        ORDER BY visited_on
        RANGE BETWEEN INTERVAL '6 days' PRECEDING AND CURRENT ROW
    )AS amount,
    ROUND(
        AVG(daily_total.sum_amount) OVER(
            ORDER BY daily_total.visited_on
            RANGE BETWEEN INTERVAL '6 days' PRECEDING AND CURRENT ROW
        )::NUMERIC,
        2
    )
    AS average_amount,
    MIN(daily_total.visited_on) OVER(
        ORDER BY daily_total.visited_on
        RANGE BETWEEN INTERVAL '6 days' PRECEDING AND CURRENT ROW
    ) AS min_day
    FROM daily_total
)
SELECT visited_on,amount,average_amount
FROM windowed
WHERE visited_on - min_day = 6
ORDER BY visited_on ASC;