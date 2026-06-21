# Write your MySQL query statement below
select 
    c1.user_id,
    case 
        when c2.confirmed is null or c2.total is null then 0
        else round(c2.confirmed/c2.total,2)
    end as confirmation_rate

 from signups c1
left join 
    (select user_id,
        sum(case when action='confirmed' then 1 else 0 end) as confirmed,
        count(user_id) as total
    from confirmations
    group by user_id
    ) as c2
on c1.user_id=c2.user_id;