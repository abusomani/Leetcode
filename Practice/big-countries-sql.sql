/* Write your PL/SQL query statement below */
select name as "name", population as "population", area as "area"
from World
where area > 3000000 or population > 25000000