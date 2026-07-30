# Write your MySQL query statement below

select
m.employee_id,
m.name, 
n.reports_count as reports_count,
n.avg_age as average_age
from Employees m
join (
    select 
        reports_to,
        count(reports_to) as reports_count,
        round(avg(age),0) as avg_age
        from Employees
        group by reports_to
        having reports_to is not NULL
) as n
on m.employee_id =n.reports_to

order by employee_id;