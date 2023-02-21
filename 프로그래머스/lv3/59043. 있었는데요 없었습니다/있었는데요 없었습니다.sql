-- 코드를 입력하세요
select 
    ao.animal_id as animal_id,
    ao.name as name
from animal_outs as ao
    left join animal_ins as ai on ai.animal_id = ao.animal_id
where ao.datetime < ai.datetime
order by ai.datetime