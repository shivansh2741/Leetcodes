# Write your MySQL query statement below
select reports_to as employee_id , 
(select name from Employees as e2 where e1.reports_to = e2.employee_id) as name
,count(reports_to) as reports_count , 
round(avg(age)) as average_age 
from Employees as e1
group by reports_to
having reports_to is not null
order by employee_id