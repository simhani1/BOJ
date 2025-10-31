select
    fi.id,
    fni.fish_name,
    fi.length
from fish_info fi
    inner join fish_name_info fni on fni.fish_type = fi.fish_type
where fi.fish_type in 
(
    select fish_type
    from fish_info
    group by fish_type
    having length = max(length)
)
order by fi.id asc