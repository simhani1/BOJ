select
    year(ym) as 'year',
    round(avg(pm_val1), 2) as 'pm10',
    round(avg(pm_val2), 2) as 'pm2.5'
from air_pollution
where location2 = '수원'
group by year(ym)
order by `year` asc


# SELECT YEAR(YM) AS "YEAR", 
#        ROUND(AVG(PM_VAL1), 2) AS "PM10", 
#        ROUND(AVG(PM_VAL2), 2) AS "PM2.5"
# FROM AIR_POLLUTION
# WHERE LOCATION2 = '수원'
# GROUP BY YEAR(YM) 
# ORDER BY 1 ASC;