# Write your MySQL query statement below

-- select w2.id from weather w1
-- where w1.temperature < (select w2.temperature from weather w2 where w2.recordDate=date_add(w1.recordDate, interval 1 day));

-- select w1.id from weather w1
-- where w1.temperature > (select w2.temperature from weather w2 where w2.recordDate = date_add(w1.recordDate, interval -1 day));

select today.id from weather today
join weather yesterday 
    on today.recordDate= date_add(yesterday.recordDate, interval 1 day)
where today.temperature > yesterday.temperature;