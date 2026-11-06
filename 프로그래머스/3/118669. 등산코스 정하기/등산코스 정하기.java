import java.util.*; 

class Edge {
    int now, cost;
    public Edge(int now, int cost) {
        this.now = now;
        this.cost = cost;
    }
}

class Solution {
    int N;
    int [][] paths;
    int[] gates, summits;
    List<Edge>[] edges;
    Set<Integer> gateSet, summitSet;
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        this.N = n;
        this.paths = paths;
        this.gates = gates;
        this.summits = summits;
        
        gateSet = new HashSet<>();
        for (int gate : gates) {
            gateSet.add(gate); 
        }
        summitSet = new HashSet<>();
        for (int summit : summits) {
            summitSet.add(summit);
        }
        
        edges = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            edges[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < paths.length; i++) {
            edges[paths[i][0]].add(new Edge(paths[i][1], paths[i][2]));
            edges[paths[i][1]].add(new Edge(paths[i][0], paths[i][2]));
        }
        
        int[] intensity = dijkstra(gates);

               
        int[] answer = {-1, Integer.MAX_VALUE};
        Arrays.sort(summits);
        for (int summit : summits) {
            if (intensity[summit] < answer[1]) {
                answer[0] = summit;
                answer[1] = intensity[summit];
            }
        }
        return answer;
    }

    int[] dijkstra(int[] gates) {
        int[] intensity = new int[N + 1];
        Arrays.fill(intensity, Integer.MAX_VALUE);
        
        Queue<Edge> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        for (int gate : gates) {
            intensity[gate] = 0;
            pq.offer(new Edge(gate, 0));
        }
        
        while (!pq.isEmpty()) {
            Edge curr = pq.poll();
            int now = curr.now;
            int nowCost = curr.cost; 
            
            if (intensity[now] < nowCost) {
                continue;
            }
            
            if (summitSet.contains(now)) {
                continue;
            }
            
            for (Edge edge : edges[now]) {
                int next = edge.now;
                
                if (gateSet.contains(next)) {
                    continue;
                }
                
                int nextIntensity = Math.max(nowCost, edge.cost);
                
                if (nextIntensity < intensity[next]) {
                    intensity[next] = nextIntensity;
                    pq.offer(new Edge(next, nextIntensity));
                }
            }
        }
        
        return intensity;
    }
}