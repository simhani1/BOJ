select
    distinct d.id,
    d.email,
    d.first_name,
    d.last_name
from developers d
join skillcodes s on s.code & d.skill_code and s.category = 'Front End'
order by id asc