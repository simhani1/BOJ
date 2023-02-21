-- 코드를 입력하세요
select
    year(os.sales_date) as year,
    month(os.sales_date) as month,
    ui.gender as gender,
    count(distinct os.user_id) as users  # 2022-01-02, 2022-01-03에 같은 사람이 구매를 했으면 1월에 구매한 회원수는 1이다. 따라서 distinct를 사용하여 범주 조회를 사용해야 한다.
from online_sale as os
    left join user_info as ui on ui.user_id = os.user_id
where gender is not null
group by year, month, gender
order by year, month, gender
