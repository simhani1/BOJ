select 
    ugb.writer_id,
    ugu.nickname,
    sum(ugb.price) as 'total_sales'
from used_goods_board ugb
    inner join used_goods_user ugu
    on ugb.writer_id = ugu.user_id
where status = 'DONE'
group by ugb.writer_id
having `total_sales` >= 700000
order by `total_sales` asc