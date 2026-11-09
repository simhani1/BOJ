import java.util.*;

class Solution {
    Set<String> set = new HashSet<>();
    public int[] solution(String[] gems) {
        for (String gem : gems) {
            set.add(gem);
        }
        
        int l = 1, r = gems.length;
        int[] answer = {};
        while (l <= r) {
            int mid = (l + r) / 2;
            int[] res = check(mid, gems);
            if (res[0] == 1) {
                answer = new int[]{res[1], res[2]};
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return answer;
    }
    
    int[] check(int p, String[] gems) {
        Map<String, Integer> map = new HashMap<>();
        int[] ret = new int[3];
        for (int i = 0; i < p; i++) {
            map.put(gems[i], map.getOrDefault(gems[i], 0) + 1);
        }
        if (map.size() == set.size()) {
            return new int[]{1, 1, p};
        }
        
        for (int i = 1; i + p <= gems.length; i++) {
            String removed = gems[i - 1];
            map.put(removed, map.get(removed) - 1);
            if (map.get(removed) == 0) {
                map.remove(removed);
            }
            
            String added = gems[i + p - 1];
            map.put(added, map.getOrDefault(added, 0) + 1);
            
            if (map.size() == set.size()) {
                return new int[]{1, i + 1, i + p};
            }
        }
        return ret;
    }
}