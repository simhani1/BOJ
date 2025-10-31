select 
    a.apnt_no,
    p.pt_name,
    a.pt_no,
    a.mcdp_cd,
    d.dr_name,
    a.apnt_ymd
from appointment a
    join doctor d on d.dr_id = a.mddr_id
    join patient p on p.pt_no = a.pt_no
where
    a.apnt_cncl_yn = 'N' 
    and date_format(apnt_ymd, '%Y-%m-%d') = '2022-04-13'
    and a.mcdp_cd = 'CS'
order by a.apnt_ymd asc