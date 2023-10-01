# Write your MySQL query statement below

select num
from MyNumbers
group by num
having count(num) = 1
UNION SELECT NULL 
ORDER BY num DESC LIMIT 1;



# select max(num) as num
# from 
# (select num from MyNumbers
# group by num
# having count(num) = 1) as unique_numbers
