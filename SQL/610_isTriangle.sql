\c Leetcode

Create table If Not Exists Triangle (x int, y int, z int);

SELECT x,y,z,
CASE
    WHEN x+y>z AND x+z>y AND y+z>x
    THEN 'Yes'
    ELSE 'No'
END AS triangle
FROM Triangle;
