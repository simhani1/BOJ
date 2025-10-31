select
    case   
        when (skill_code & (select sum(code) from skillcodes where category like 'Front%')) and (skill_code & (select code from skillcodes where name = 'Python'))
            then
                'A'
        when skill_code & (select code from skillcodes where name = 'C#')
            then
                'B'
        when skill_code & (select sum(code) from skillcodes where category like 'Front%')
            then
                'C'
        else 
            null
    end as grade,
    id,
    email
from developers
having grade is not null
order by grade asc, id asc