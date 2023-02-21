-- 코드를 입력하세요
# 사용자 정의 변수
set @i = -1;

select  
    (@i:= @i +1) as hour,
    (select 
        count(animal_id) 
     from animal_outs 
     where hour(datetime) = @i) as count
from animal_outs
where @i < 23