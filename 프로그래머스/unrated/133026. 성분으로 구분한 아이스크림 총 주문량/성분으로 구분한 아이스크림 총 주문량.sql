-- 코드를 입력하세요
select 
    ii.ingredient_type as ingredient_type,
    sum(fh.total_order) as total_order
from icecream_info as ii
left join
(
    select 
        flavor,
        sum(total_order) as total_order
    from first_half
    group by flavor
) as fh on fh.flavor = ii.flavor
group by ii.ingredient_type
order by 2


