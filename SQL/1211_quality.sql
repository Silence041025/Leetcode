\c Leetcode

Create table If Not Exists Queries (query_name varchar(30), result varchar(50), position int, rating int);

SELECT Queries.query_name,
ROUND(
    SUM(Queries.rating::NUMERIC/Queries.position) / COUNT(Queries.rating),
    2
)
AS quality,
ROUND(
    COUNT(CASE WHEN Queries.rating < 3 THEN 1 END)::NUMERIC * 100 / COUNT(Queries.rating),
    2
)
AS poor_query_percentage
FROM Queries
GROUP BY query_name;