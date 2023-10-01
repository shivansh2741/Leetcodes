# Write your MySQL query statement below
with t1 as(
    select product_id , min(year) as year
    from Sales
    group by product_id
)

select s.product_id,s.year as first_year,s.quantity,s.price
from Sales as s
inner join
t1 on t1.product_id = s.product_id and s.year = t1.year