import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, K;
    private static List<Node>[] edgeList;
    private static boolean[] supply;
    private static int[] parent;
    private static PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> {
        return Integer.compare(o1.cost, o2.cost);
    });

    static class Node {
        int to;
        int cost;

        public Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }
    }

    static class Edge {
        int from;
        int to;
        int cost;

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        supply = new boolean[N + 1];
        parent = new int[N + 1];
        edgeList = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            edgeList[i] = new ArrayList<>();
            parent[i] = i;
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            int city = Integer.parseInt(st.nextToken());
            supply[city] = true;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());
            edgeList[A].add(new Node(B, C));
            edgeList[B].add(new Node(A, C));
            if (supply[A]) {
                pq.offer(new Edge(A, B, C));
            } else if (supply[B]) {
                pq.offer(new Edge(B, A, C));
            }
        }
        System.out.println(solve());
    }

    private static int solve() {
        int sum = 0;
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (Find(from) != Find(to) && !supply[to]) {
                Union(from, to);
                sum += cost;
                /* 다음 노드에서 연결 가능한 간선 정보 저장 */
                for (Node node : edgeList[to]) {
                    int next = node.to;
                    int nextCost = node.cost;
                    pq.offer(new Edge(to, next, nextCost));
                }
            }
            if (canSupplyAllCity()) {
                break;
            }
        }
        return sum;
    }

    private static boolean canSupplyAllCity() {
        for (int i = 1; i <= N; i++) {
            if (!supply[i]) {
                return false;
            }
        }
        return true;
    }

    private static void Union(int a, int b) {
        a = Find(a);
        b = Find(b);
        if (a != b) {
            parent[Math.max(a, b)] = Math.min(a, b);
            supply[a] = supply[b] = true;
        }
    }

    private static int Find(int a) {
        if (a == parent[a]) {
            return a;
        }
        return parent[a] = Find(parent[a]);
    }
}