\c Leetcode

Create table If Not Exists Visits(visit_id int, customer_id int);
Create table If Not Exists Transactions(transaction_id int, visit_id int, amount int);

SELECT Visits.customer_id,COUNT(*) AS count_no_trans
FROM Visits LEFT JOIN Transactions T on Visits.visit_id = T.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id;
