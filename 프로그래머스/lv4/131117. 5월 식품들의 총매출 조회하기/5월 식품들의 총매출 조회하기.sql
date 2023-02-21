-- 코드를 입력하세요
select
    fp.product_id as product_id,
    fp.product_name as product_name,
    (fp.price * fo.total_count) as total_sales
from food_product as fp 
    inner join (
        select 
            product_id,
            sum(amount) as total_count
        from food_order
        where produce_date like '2022-05%'
        group by product_id
    ) as fo on fo.product_id = fp.product_id
order by total_sales desc, product_id