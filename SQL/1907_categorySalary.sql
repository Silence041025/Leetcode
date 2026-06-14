\c Leetcode
Create table If Not Exists Accounts (account_id int, income int);

WITH Categories
AS(
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
),
AccountsWithCategory
AS(
    SELECT Accounts.account_id,
    CASE
        WHEN Accounts.income < 20000
        THEN 'Low Salary'
        WHEN Accounts.income >= 20000 AND Accounts.income <= 50000
        THEN 'Average Salary'
        ELSE 'High Salary'
    END AS category
    FROM Accounts
)
SELECT
Categories.category,
COUNT(account_id) AS accounts_count
FROM Categories LEFT JOIN AccountsWithCategory
ON Categories.category = AccountsWithCategory.category
GROUP BY Categories.category;