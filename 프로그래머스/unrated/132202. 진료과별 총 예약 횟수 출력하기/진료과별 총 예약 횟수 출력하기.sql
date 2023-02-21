-- 코드를 입력하세요
select 
    mcdp_cd as '진료과 코드',
    count(apnt_no) as '5월예약건수'
from appointment
where apnt_ymd like '2022-05%'
group by mcdp_cd
order by count(apnt_no), mcdp_cd

