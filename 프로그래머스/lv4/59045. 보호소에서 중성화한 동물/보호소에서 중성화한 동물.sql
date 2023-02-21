-- 코드를 입력하세요
select
    ao.animal_id as animal_id,
    ao.animal_type as animal_type,
    ao.name as name
from animal_outs as ao
    left join animal_ins as ai on ai.animal_id = ao.animal_id
where 
    ai.sex_upon_intake regexp 'Intact' and 
    ao.sex_upon_outcome regexp 'Spayed|Neutered'
order by animal_id
