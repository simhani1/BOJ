with child_count_cte as (
    select
        parent_id,
        count(*) as `count`
    from ecoli_data
    group by parent_id
    having parent_id is not null
)
select
    ed.id,
    ifnull(ccc.count, 0) as child_count
from ecoli_data ed
left join child_count_cte ccc on ccc.parent_id = ed.id
order by ed.id asc