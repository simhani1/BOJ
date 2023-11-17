import java.util.*;

/*
양방향
등산로별 시간 소요
쉼터 또는 산봉우리를 방문 -> 휴식 가능, 휴식 없이 디옹해야 하는 시간 중 가장 긴 시간 === intensity
산봉우리 중 한 곳만 방문한 뒤 돌아오기 -> 즉 출입구, 산봉우리는 하나만 방문 가능
이 규칙을 지키며 intensity가 최소가 되는 코스를 찾기
*/

class Node {
    int idx;
    int intensity;
    
    public Node(int idx, int intensity){
        this.idx = idx;
        this.intensity = intensity;
    }
}

class Solution {
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        // 정점까지의 최소 intensity 저장
        int[] intensity = new int[n + 1];
        Arrays.fill(intensity, Integer.MAX_VALUE);
        
        // 도착지 체크
        boolean[] isSummit = new boolean[n + 1];
        for(int summit : summits){
            isSummit[summit] = true;
        }
        
        // 그래프 생성
        List<List<Node>> arr = new ArrayList<>();
        for(int i=0;i<=n;i++){
            arr.add(new ArrayList<>());
        }
        for(int[] p : paths){
            int from = p[0];
            int to = p[1];
            int cost = p[2];    
            arr.get(from).add(new Node(to, cost));
            arr.get(to).add(new Node(from, cost));
        }
    
        // 다익스트라
        Queue<Node> q = new LinkedList<>();
        for(int gate : gates){
            q.add(new Node(gate, 0));
            intensity[gate] = 0;
        }
        while(!q.isEmpty()){
            Node now = q.poll();   
            // 현재 경로로 온 경우의 intensity > 다른 경로로 온 경우의 intensity
            if(now.intensity > intensity[now.idx])
                continue;
            for(Node next : arr.get(now.idx)){
                // max(지금까지의 intensity중 최댓값, 다음 정점까지의 intensity)
                int maxIntensity = Math.max(now.intensity, next.intensity);
                // 다른 경로로 다음 정점까지 간 경우의 intensity > 현재 경로로 다음 정점까지 간 경우의 intensity
                if(intensity[next.idx] > maxIntensity){
                    intensity[next.idx] = maxIntensity;
                    // 산봉우리인 경우 stop
                    if(isSummit[next.idx])
                        continue;
                    q.add(new Node(next.idx, maxIntensity));
                }
            }
        }
        int ansIdx = Integer.MAX_VALUE;
        int ansIntensity = Integer.MAX_VALUE;
        for(int summit : summits){
            if(intensity[summit] < ansIntensity){
                ansIdx = summit;  
                ansIntensity = intensity[summit];
            }
            else if(intensity[summit] == ansIntensity && summit < ansIdx){
                ansIdx = summit;   
                ansIntensity = intensity[summit];
            }
        }
        int[] answer = {ansIdx, ansIntensity};
        return answer;
    }
}