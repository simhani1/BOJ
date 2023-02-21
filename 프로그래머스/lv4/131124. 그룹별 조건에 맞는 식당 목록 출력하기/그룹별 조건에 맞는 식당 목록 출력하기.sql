-- 코드를 입력하세요
select
    mp.member_name as member_name,
    rr.review_text as review_text,
    date_format(rr.review_date, '%Y-%m-%d') as review_date
from member_profile as mp
    join rest_review as rr on rr.member_id = mp.member_id
where rr.member_id = (
        select
            member_id
        from rest_review
        group by member_id
        order by count(review_id) desc
        limit 1)
order by review_date, review_text