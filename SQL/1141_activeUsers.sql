\c Leetcode

CREATE TABLE IF NOT EXISTS Activity (
    user_id INT,
    session_id INT,
    activity_date DATE,
    activity_type VARCHAR(20) CHECK (activity_type IN ('open_session', 'end_session', 'scroll_down', 'send_message'))
);

SELECT
Activity.activity_date AS day,
COUNT(DISTINCT Activity.user_id) AS active_users
FROM Activity
GROUP BY Activity.activity_date
HAVING activity_date > '2019-06-27' AND activity_date < '2019-08-25';