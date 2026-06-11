\c Leetcode

Create table If Not Exists World (name varchar(255), continent varchar(255), area int, population int, gdp bigint);

SELECT World.name,World.population,World.area FROM World
WHERE area >= 3000000 OR population >= 25000000;