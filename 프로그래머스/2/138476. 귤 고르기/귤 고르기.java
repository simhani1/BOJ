import java.util.*;

class Solution {
    
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        // 1 2 2 3 3 4 5 5
        // 크기별 개수를 기준으로 내림차순 정렬, 많은것부터 소모해서 k개 만들기, 서로 다른 귤의 크기 개수 구하기
        Map<Integer, Integer> m = new HashMap<>();
        for(int t : tangerine){
            m.put(t, m.getOrDefault(t, 0) + 1);
        }
        List<Integer> value = new ArrayList<>(m.values());
        Collections.sort(value, Collections.reverseOrder());
        int tmp = 0;
        for(int v: value){
            if(tmp < k){
                tmp += v;
                answer++;
            }
        }
        return answer;
    }
}