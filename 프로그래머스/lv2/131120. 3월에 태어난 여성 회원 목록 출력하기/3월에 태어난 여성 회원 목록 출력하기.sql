-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, 
date_format(date_of_birth, "%Y-%m-%d") as 'DATE_OF_BIRTH'
from member_profile
where tlno is not null 
and MONTH(DATE_OF_BIRTH)=3
and GENDER='W';