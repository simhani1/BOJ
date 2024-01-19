import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int V, E, K;
    static int[] dist;
    static List<Node>[] arr;

    static PriorityQueue<Node> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken());
        arr = new ArrayList[V + 1];
        for (int i = 0; i <= V; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            arr[u].add(new Node(v, w));
        }
        dist = new int[V + 1];
        for (int i = 1; i <= V; i++) {
            dist[i] = Integer.MAX_VALUE;
        }

        // solve
        dijkstra(K);

        // ans
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (dist[i] != Integer.MAX_VALUE) {
                sb.append(dist[i]).append("\n");
            } else {
                sb.append("INF\n");
            }
        }
        System.out.println(sb.toString());
    }

    private static void dijkstra(int start) {
        dist[start] = 0;
        pq.offer(new Node(start, 0));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int now = node.node;
            int cost = node.cost;
            for (int i = 0; i < arr[now].size(); i++) {
                Node nextNode = arr[now].get(i);
                int next = nextNode.node;
                int nextCost = nextNode.cost;
                if (dist[next] > cost + nextCost) {
                    dist[next] = cost + nextCost;
                    pq.offer(new Node(next, dist[next]));
                }
            }
        }
    }
}

class Node implements Comparable<Node> {
    int node;
    int cost;

    Node(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public int compareTo(Node target) {
        return this.cost - target.cost;
    }
}