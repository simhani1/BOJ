select
    p.product_code,
    p.price * sum(os.sales_amount) as sales
from product p
inner join offline_sale os on os.product_Id = p.product_id
group by p.product_code
order by sales desc, product_code asc