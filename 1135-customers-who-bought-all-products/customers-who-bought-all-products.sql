# Write your MySQL query statement below

select customer_id from (
    select Distinct * from Customer
) as uniq
group by customer_id
having count(customer_id) = (select count(product_key) from Product);