select 
    ed.id,
    ed.genotype,
    ed2.genotype as 'parent_genotype'
from ecoli_data ed
    inner join 
        ecoli_data ed2
    on ed.parent_id = ed2.id
where ed.genotype & ed2.genotype = ed2.genotype
order by ed.id asc