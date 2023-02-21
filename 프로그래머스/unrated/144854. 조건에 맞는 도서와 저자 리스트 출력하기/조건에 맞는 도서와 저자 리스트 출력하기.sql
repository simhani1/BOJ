-- 코드를 입력하세요
select 
    b.book_id as book_id,
    a.author_name as author_name,
    date_format(b.published_date, '%Y-%m-%d') as published_date
from book as b
    left join author as a on a.author_id = b.author_id
where b.category = '경제'
order by published_date