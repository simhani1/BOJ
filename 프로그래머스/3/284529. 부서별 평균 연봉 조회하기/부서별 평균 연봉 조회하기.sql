-- 코드를 작성해주세요

select
    HD.DEPT_ID,
    HD.DEPT_NAME_EN,
    round(avg(HE.SAL)) as AVG_SAL
from HR_DEPARTMENT HD
    inner join HR_EMPLOYEES HE on HE.DEPT_ID = HD.DEPT_ID
group by HD.DEPT_ID
order by AVG_SAL desc
;