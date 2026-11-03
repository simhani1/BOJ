import java.util.*;

class Solution {
    
    public int[] solution(String[] info, String[] query) {
        Map<String, List<Integer>> map = new HashMap<>();
        
        for (String str : info) {
            String[] arr = str.split(" ");
            int score = Integer.parseInt(arr[4]);
            
            for (int mask = 0; mask < 16; mask++) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < 4; i++) {
                    if ((mask & 1 << i) != 0) {
                        sb.append("-");
                    } else {
                        sb.append(arr[i]);
                    }
                }
                String key = sb.toString();
                map.computeIfAbsent(key, k -> new ArrayList<>())
                    .add(score);
            }
        }
        
        for (List<Integer> scores : map.values()) {
            Collections.sort(scores);
        }
        
        int[] answer = new int[query.length];
        for (int i = 0; i < query.length; i++) {
            String[] arr = query[i].replace(" and ", " ").split(" ");
            String key = arr[0] + arr[1] + arr[2] + arr[3];
            int target = Integer.parseInt(arr[4]);
            
            List<Integer> scores = map.getOrDefault(key, Collections.emptyList());
            int idx = lowerBound(scores, target);
            answer[i] = scores.size() - idx;
        }
        return answer;
    }
    
    int lowerBound(List<Integer> scores, int target) {
        int l = 0, r = scores.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (scores.get(mid) >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}