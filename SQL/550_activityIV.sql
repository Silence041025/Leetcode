\c Leetcode

Create table If Not Exists Activity (player_id int, device_id int, event_date date, games_played int);

WITH Activity_with_date_number
AS(
    SELECT Activity.player_id,Activity.event_date,
    ROW_NUMBER() OVER(
        PARTITION BY Activity.player_id
        ORDER BY Activity.event_date ASC
    ) AS date_number
    FROM Activity
),
First_Activity AS(
    SELECT
    Activity_with_date_number.player_id,
    Activity_with_date_number.event_date
    FROM Activity_with_date_number
    WHERE Activity_with_date_number.date_number = 1
)
SELECT
ROUND(
    COUNT(
    CASE
        WHEN Activity.event_date = First_Activity.event_date + 1
        THEN 1
    END
    )::NUMERIC /
    (SELECT COUNT(*) FROM First_Activity),
    2
)
AS fraction
FROM Activity INNER JOIN First_Activity
ON Activity.player_id = First_Activity.player_id;