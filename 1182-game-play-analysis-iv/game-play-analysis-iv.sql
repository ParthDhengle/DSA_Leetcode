# Write your MySQL query statement below

select 
round(
    (count(a.player_id)/
    (select count(distinct(player_id)) from Activity)) , 2
) as fraction

from Activity as a
join
(select 
player_id,
min(event_date) as min_date
from Activity
group by player_id) as f
on a.player_id=f.player_id and a.event_date=date_add(f.min_date, interval 1 day)
;