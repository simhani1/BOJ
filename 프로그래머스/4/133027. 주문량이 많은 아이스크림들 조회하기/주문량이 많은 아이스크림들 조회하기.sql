select fh.flavor
from first_half fh
         inner join (select flavor, sum(total_order) as july_total_order
                     from july
                     group by flavor) j on fh.flavor = j.flavor
order by fh.total_order + j.july_total_order desc
limit 3;