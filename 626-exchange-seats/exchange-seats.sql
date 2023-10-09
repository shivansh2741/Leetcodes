# Write your MySQL query statement below
with t1 as(
  select *,
  lag(student) over() as prev_student,
  lead(student) over() as next_student
  from Seat
)

select id , coalesce(if(id%2 = 0 ,prev_student, next_student) , student) as student
from t1