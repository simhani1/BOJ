-- 코드를 입력하세요
select 
    a.author_id as author_id,
    a.author_name as author_name,
    b.category as category,
    sum(b.price * bs.total_sales) as total_sales
from book as b
left join author as a on a.author_id = b.author_id
inner join(
    select
        book_id,
        sum(sales) as total_sales
    from book_sales
    where sales_date like '2022-01%'
    group by book_id
) as bs on bs.book_id = b.book_id
group by a.author_id, b.category
order by b.author_id asc, b.category desc