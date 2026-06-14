\c Leetcode
CREATE TABLE IF NOT EXISTS Transactions (
    id INTEGER,
    country VARCHAR(4),
    state VARCHAR(20),
    amount INTEGER,
    trans_date DATE,
    CONSTRAINT state_check CHECK (state IN ('approved', 'declined'))
);

SELECT TO_CHAR(Transactions.trans_date,'YYYY-MM') AS month,
Transactions.country,
COUNT(Transactions.id) AS trans_count,
COUNT(CASE WHEN Transactions.state = 'approved' THEN 1 END) AS approved_count,
SUM(Transactions.amount) AS trans_total_amount,
CASE
    WHEN SUM(CASE WHEN Transactions.state = 'approved' THEN Transactions.amount END) IS NULL
    THEN 0
    ELSE
    SUM(CASE WHEN Transactions.state = 'approved' THEN Transactions.amount END)
END
AS approved_total_amount
FROM Transactions
GROUP BY TO_CHAR(Transactions.trans_date,'YYYY-MM'), Transactions.country;

