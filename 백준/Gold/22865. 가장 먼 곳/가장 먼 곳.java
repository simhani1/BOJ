import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[] arr;
    private static int[] distA, distB, distC;
    private static List<Edge>[] adjList;

    static class Edge {
        int to;
        int cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        init();
        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        distA[arr[0]] = 0;
        distB[arr[1]] = 0;
        distC[arr[2]] = 0;
        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            adjList[from].add(new Edge(to, cost));
            adjList[to].add(new Edge(from, cost));
        }
        dijkstra(arr[0], distA);
        dijkstra(arr[1], distB);
        dijkstra(arr[2], distC);
        int maxCost = 0;
        int ans = 0;
        for (int i = N; i >= 1; i--) {
            int minCost = Integer.MAX_VALUE;
            minCost = Math.min(distA[i], Math.min(distB[i], distC[i]));
            if (minCost == 0) {
                continue;
            }
            if (maxCost <= minCost) {
                maxCost = minCost;
                ans = i;
            }
        }
        System.out.println(ans);
    }

    private static void dijkstra(int start, int[] dist) {
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        pq.offer(new Edge(start, 0));
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int now = edge.to;
            int cost = edge.cost;
            for (int i = 0; i < adjList[now].size(); i++) {
                int next = adjList[now].get(i).to;
                int nextCost = adjList[now].get(i).cost;
                if (dist[next] > dist[now] + nextCost) {
                    dist[next] = dist[now] + nextCost;
                    pq.offer(new Edge(next, dist[next]));
                }
            }
        }
    }

    private static void init() {
        arr = new int[N + 1];
        distA = new int[N + 1];
        distB = new int[N + 1];
        distC = new int[N + 1];
        Arrays.fill(distA, Integer.MAX_VALUE);
        Arrays.fill(distB, Integer.MAX_VALUE);
        Arrays.fill(distC, Integer.MAX_VALUE);
        adjList = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            adjList[i] = new ArrayList<>();
        }
    }

}