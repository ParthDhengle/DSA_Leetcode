# Write your MySQL query statement below
-- select p.product_id,
-- COALESCE((
--     select pr.new_price from products pr
--     where pr.product_id = p.product_id and pr.change_date<='2019-08-16'
--     order by pr.change_date desc limit 1
-- ),10) as price
-- from Products as p
-- group by p.product_id;

select 
    p.product_id,
    COALESCE(latest.new_price,10) as price 
from products p
LEFT join (
    select 
        pr.product_id, 
        pr.new_price 
    from Products pr
    where (pr.product_id,pr.change_date) in (
        select 
            product_id,
            max(change_date) 
        from products
        where change_date <= '2019-08-16'
        group by product_id
    )
) latest      
on p.product_id=latest.product_id
group by p.product_id;

