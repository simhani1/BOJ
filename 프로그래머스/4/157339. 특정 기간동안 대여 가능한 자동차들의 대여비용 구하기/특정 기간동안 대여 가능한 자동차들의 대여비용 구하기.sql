select
    crcc.car_id,
    crcc.car_type,
    round(30 * crcc.daily_fee * (100 - crcdp.discount_rate) / 100) as fee
from car_rental_company_car crcc
    join car_rental_company_discount_plan crcdp
    on crcdp.car_type = crcc.car_type and crcdp.duration_type = '30일 이상'
where 1 = 1
    and crcc.car_type in ('세단', 'SUV')
    and crcc.car_id not in
    (
        select car_id
        from car_rental_company_rental_history
        where start_date <= '2022-11-30' and end_date >= '2022-11-01'
    )
having 500000 <= fee and fee < 2000000
order by fee desc, car_type asc, car_id desc