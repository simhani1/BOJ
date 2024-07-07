select
    it.item_id,
    ii.item_name,
    ii.rarity
from item_tree it
    left join item_info ii
    on it.item_id = ii.item_id
where it.item_id not in (select it2.parent_item_id from item_tree it2 where it2.parent_item_id is not null)
order by it.item_id desc