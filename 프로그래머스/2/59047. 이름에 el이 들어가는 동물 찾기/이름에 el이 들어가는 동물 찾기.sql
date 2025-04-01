select
    ai.ANIMAL_ID,
    ai.NAME
from ANIMAL_INS ai
where ai.NAME like '%EL%'
    and ai.ANIMAL_TYPE = 'Dog'
order by ai.NAME asc
;

