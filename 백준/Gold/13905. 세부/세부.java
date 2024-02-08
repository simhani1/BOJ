import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, S, E;
    private static List<Node>[] arr;
    private static int[] parent;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        arr = new ArrayList[N + 1];
        parent = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            arr[i] = new ArrayList<>();
            parent[i] = i;
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            arr[A].add(new Node(B, K));
            arr[B].add(new Node(A, K));
        }
        int ans = mst(S);
        if (Find(S) != Find(E)) {
            System.out.println(0);
            return;
        }
        System.out.println(ans);
    }

    private static void Union(int A, int B) {
        A = Find(A);
        B = Find(B);
        if (A != B) {
            parent[Math.max(A, B)] = Math.min(A, B);
        }
    }

    private static int Find(int A) {
        if (A == parent[A]) {
            return A;
        }
        return parent[A] = Find(parent[A]);
    }

    private static int mst(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost) * -1);
        int ans = Integer.MAX_VALUE;
        int edgeCnt = 0;
        for (int i = 0; i < arr[start].size(); i++) {
            Node node = arr[start].get(i);
            pq.offer(new Edge(start, node.to, node.cost));
        }
        while (!pq.isEmpty()) {
            Edge edge = pq.poll();
            int from = edge.from;
            int to = edge.to;
            int cost = edge.cost;
            if (Find(from) == Find(to)) {
                continue;
            }
            Union(from, to);
            edgeCnt++;
            ans = Math.min(ans, cost);
            if (to == E) {
                break;
            }
            for (int i = 0; i < arr[to].size(); i++) {
                pq.offer(new Edge(to, arr[to].get(i).to, arr[to].get(i).cost));
            }
        }
        return ans;
    }
}

class Node {
    int to;
    int cost;

    public Node(int to, int cost) {
        this.to = to;
        this.cost = cost;
    }
}

class Edge {
    int from;
    int to;
    int cost;

    public Edge(int from, int to, int cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}