# Write your MySQL query statement below

-- select w2.id from weather w1
-- where w1.temperature < (select w2.temperature from weather w2 where w2.recordDate=date_add(w1.recordDate, interval 1 day));

select w1.id from weather w1
where w1.temperature > (select w2.temperature from weather w2 where w2.recordDate = date_add(w1.recordDate, interval -1 day));