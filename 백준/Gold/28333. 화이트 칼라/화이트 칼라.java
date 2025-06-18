import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int T, N, M;
    static int[] dist;
    static List<Integer>[] edge;
    static List<Integer>[] parent;
    static boolean[] visited;
    static Queue<Integer> pq = new PriorityQueue<>();

    static class Node {
        int num;
        int cost;

        public Node(int num, int cost) {
            this.num = num;
            this.cost = cost;
        }

        @Override
        public String toString() {
            return "Node{" +
                "num=" + num +
                ", cost=" + cost +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            edge = new ArrayList[N + 1];
            dist = new int[N + 1];
            parent = new ArrayList[N + 1];
            visited = new boolean[N + 1];
            for (int i = 0; i <= N; i++) {
                edge[i] = new ArrayList<>();
                parent[i] = new ArrayList<>();
                dist[i] = 987654321;
            }
            for (int i = 0; i < M; i++) {
                st = new StringTokenizer(br.readLine());
                int from =  Integer.parseInt(st.nextToken());
                int to =  Integer.parseInt(st.nextToken());
                edge[from].add(to);
            }
            bfs(1);
            dfs(N);
            while (!pq.isEmpty()) {
                sb.append(pq.poll()).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    private static void dfs(int now) {
        visited[now] = true;
        pq.offer(now);
        if (now == 1) {
            return;
        }
        for (int p : parent[now]) {
            if (!visited[p]) {
                dfs(p);
            }
        }
    }

    private static void bfs(int start) {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(start, 0));
        dist[start] = 0;
        while (!q.isEmpty()) {
            Node node = q.poll();
            int now = node.num;
            int nowCost = node.cost;
            for (int next : edge[now]) {
                if (dist[next] > nowCost + 1) {
                    dist[next] = nowCost + 1;
                    parent[next].add(now);
                    q.offer(new Node(next, dist[next]));
                } else if (dist[next] == nowCost + 1) {
                    parent[next].add(now);
                }
            }
        }
    }
}
