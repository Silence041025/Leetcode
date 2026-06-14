\c Leetcode
Create Table If Not Exists Insurance (pid int, tiv_2015 float, tiv_2016 float, lat float, lon float);

WITH
windowed AS(
    SELECT pid,tiv_2015,tiv_2016,lat,lon,
    COUNT(*) OVER(PARTITION BY (lat,lon)) AS loc_unique
    FROM Insurance
)
SELECT
ROUND(
    SUM(tiv_2016)::NUMERIC,
    2
) AS tiv_2016
FROM windowed
WHERE tiv_2015 IN(
    SELECT Insurance.tiv_2015
    FROM Insurance
    WHERE Insurance.pid <> windowed.pid
) AND loc_unique = 1;