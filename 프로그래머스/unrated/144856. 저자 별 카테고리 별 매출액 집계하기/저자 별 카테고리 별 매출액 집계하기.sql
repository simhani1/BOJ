-- 코드를 입력하세요
select  
    a.author_id,
    a.author_name,
    b.category,
    sum(b.price * bs.sales) as total_sales
from book as b
    left join author as a on a.author_id = b.author_id
    inner join book_sales as bs on bs.book_id = b.book_id
where bs.sales_date like '2022-01%'
group by a.author_id, b.category
order by a.author_id, b.category desc