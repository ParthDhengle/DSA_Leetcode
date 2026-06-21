# Write your MySQL query statement below

select name from Employee e1
inner join (select  managerId, count(managerId) as reports from employee 
            group by managerId) as e2
on e1.id=e2.managerId
where e2.reports >= 5;


