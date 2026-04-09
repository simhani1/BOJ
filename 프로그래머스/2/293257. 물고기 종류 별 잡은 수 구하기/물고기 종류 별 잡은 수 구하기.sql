select
    count(*) as fish_count,
    fni.fish_name
from fish_info fi
    left join fish_name_info fni on fni.fish_type = fi.fish_type
group by fni.fish_name
order by fish_count desc