\c Leetcode

CREATE TABLE IF NOT EXISTS Signups (
   user_id INT,
   time_stamp TIMESTAMP
);

CREATE TABLE IF NOT EXISTS Confirmations (
     user_id INT,
     time_stamp TIMESTAMP,
     action VARCHAR(10) CHECK (action IN ('confirmed', 'timeout'))
);

SELECT Signups.user_id,
CASE
    WHEN COUNT(action)=0 THEN 0
    ELSE
    ROUND(
        COUNT(CASE WHEN action='confirmed' THEN 1 END)::NUMERIC/
        COUNT(action)
    ,2)
END
AS confirmation_rate
FROM Signups LEFT JOIN Confirmations ON Signups.user_id = Confirmations.user_id
GROUP BY Signups.user_id;