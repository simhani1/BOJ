with init as (
    select 
        id,
        row_number() over(order by size_of_colony desc) as 'rank',  # 큰 것부터 1등
        max(id) over() as 'cnt'
    from ecoli_data
)
select
    init.id,
    case
        when init.rank <= init.cnt * 0.25 then 'CRITICAL'
        when  init.rank <= init.cnt * 0.5 then 'HIGH'
        when  init.rank <= init.cnt * 0.75 then 'MEDIUM'
        else 'LOW'
    end as 'colony_name'
from init
order by init.id asc;