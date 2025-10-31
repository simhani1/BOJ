select 
    ri.rest_id,
    ri.rest_name,
    ri.food_type,
    ri.favorites,
    ri.address,
    round(avg(rr.review_score), 2) as score
from rest_info ri
    inner join rest_review rr on rr.rest_id = ri.rest_id
where ri.address like '서울%'    
group by rr.rest_id
order by score desc, favorites desc