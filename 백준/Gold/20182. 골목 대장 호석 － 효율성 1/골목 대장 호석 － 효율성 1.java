import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import static java.util.Arrays.fill;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, A, B, C, ans = 0;
    private static List<Node>[] edge;
    private static int[] dist;
    private static final int INF = Integer.MAX_VALUE;
    private static PriorityQueue<Node> pq = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        edge = new ArrayList[N + 1];
        dist = new int[N + 1];
        for (int i = 0; i < N + 1; i++) {
            edge[i] = new ArrayList<>();
            dist[i] = INF;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            edge[from].add(new Node(to, cost));
            edge[to].add(new Node(from, cost));
        }
        for (int i = 1; i <= 20; i++) {
            dijkstra(i);
            if (dist[B] <= C) {
                System.out.println(i);
                return;
            }
            fill(dist, INF);
        }
        System.out.println(-1);
    }

    private static void dijkstra(int std) {
        dist[A] = 0;
        pq.offer(new Node(A, 0));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int now = node.v;
            int nowCost = node.cost;
            for (int i = 0; i < edge[now].size(); i++) {
                Node nextNode = edge[now].get(i);
                int next = nextNode.v;
                int nextCost = nextNode.cost;
                if (nextCost > std) {
                    continue;
                }
                if (dist[next] > nowCost + nextCost) {
                    dist[next] = nowCost + nextCost;
                    if (dist[next] <= C) {
                        ans = Math.max(ans, nowCost);
                    }
                    pq.offer(new Node(next, dist[next]));
                }
            }
        }
    }

}

class Node implements Comparable<Node> {

    int v;
    int cost;

    public Node(int v, int cost) {
        this.v = v;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node node) {
        return Integer.compare(this.cost, node.cost);  // 오름차순 정렬
    }
}