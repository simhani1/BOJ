import java.util.*;

/*
dfs로 모든 메뉴 구성을 저장, 2개 이상의 조합으로만 구혅
TreeSet에 저장하여 사전순 반환
*/

class Solution {
    
    Queue<String> pq;
    Map<String, Integer> map;
    int maxCnt;
    
    public String[] solution(String[] orders, int[] course) {
        pq = new PriorityQueue<>();
        map = new HashMap<>();
        for (int len : course) {
            map.clear();
            maxCnt = 0;
            for (String order : orders) {
                char[] arr = order.toCharArray();
                Arrays.sort(arr);
                dfs(0, arr, "", len);
            }
            for (String key : map.keySet()) {
                if (maxCnt >= 2 && map.get(key) == maxCnt) {
                    pq.offer(key);
                }
            }            
        }
        
        int N = pq.size();
        String[] ret = new String[N];
        for (int i = 0; i < N; i++) {
            ret[i] = pq.poll();
        }
        return ret;
    }
    
    private void dfs(int idx, char[] oldComb, String newComb, int len) {
        if (newComb.length() == len) {
            map.put(newComb, map.getOrDefault(newComb, 0) + 1);
            maxCnt = Math.max(maxCnt, map.get(newComb));
            return;
        }
        if (idx != oldComb.length) {
            dfs(idx + 1, oldComb, newComb + oldComb[idx], len);
            dfs(idx + 1, oldComb, newComb, len);   
        }
    }
}