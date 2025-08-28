select 
    ao.animal_id,
    ai.name
from animal_outs ao
left join animal_ins ai on ai.animal_id = ao.animal_id
order by datediff(ao.datetime, ai.datetime) desc
limit 2