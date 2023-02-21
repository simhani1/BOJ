-- 코드를 입력하세요
select 
    date_format(datetime, '%H') as hour,
    count(animal_id) as count
from animal_outs
where date_format(datetime, '%H:%i') between '09:00' and '19:59'
group by hour
order by hour