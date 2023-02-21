-- 코드를 입력하세요
select
    ai.name as name,
    ai.datetime as datetime
from animal_ins as ai
    left join animal_outs as ao on ao.animal_id = ai.animal_id
where ao.animal_id is null
order by datetime 
limit 3