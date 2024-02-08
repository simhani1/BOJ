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
    private static int N, M, K;
    private static List<Node>[] edge;
    private static int[] dist = new int[1100];
    private static boolean[] isFirst = new boolean[1100];
    private static boolean[] isLast = new boolean[1100];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        edge = new ArrayList[1100];
        for (int i = 1; i <= 1050; i++) {
            edge[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int maxStation = Integer.parseInt(st.nextToken());
            for (int j = 1; j <= maxStation; j++) {
                int key = i * 100 + j;
                // 역이 유일한 경우
                if (maxStation == 1) {
                    isFirst[key] = true;
                    isLast[key] = true;
                } else if (maxStation == 2) {

                }
                if (j == 1) {
                    isFirst[key] = true;
                    edge[key].add(new Node(key + 1, 1));
                } else if (j == maxStation) {
                    isLast[key] = true;
                    edge[key].add(new Node(key - 1, 1));
                } else {
                    edge[key].add(new Node(key + 1, 1));
                    edge[key].add(new Node(key - 1, 1));
                }
            }
        }
        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int P1 = Integer.parseInt(st.nextToken());
            int P2 = Integer.parseInt(st.nextToken());
            int Q1 = Integer.parseInt(st.nextToken());
            int Q2 = Integer.parseInt(st.nextToken());
            int key1 = P1 * 100 + P2;
            int key2 = Q1 * 100 + Q2;
            /*
            다른 노선으로 환승하여 도달 가능한 역 정보를 저장
            거리 갱신할 때 구별하기 위해 cost = -1
             */
            if (isFirst[key2] && isLast[key2]) {  // 유일한 역으로 환승하는 경우
                edge[key1].add(new Node(key2, -2));
            } else if (isFirst[key2]) {
                edge[key1].add(new Node(key2, -2));
                edge[key1].add(new Node(key2 + 1, -1));
            } else if (isLast[key2]) {
                edge[key1].add(new Node(key2, -2));
                edge[key1].add(new Node(key2 - 1, -1));
            } else {
                edge[key1].add(new Node(key2, -2));
                edge[key1].add(new Node(key2 + 1, -1));
                edge[key1].add(new Node(key2 - 1, -1));
            }
            if (isFirst[key1] && isLast[key1]) {  // 유일한 역으로 환승하는 경우
                edge[key2].add(new Node(key1, -2));
            } else if (isFirst[key1]) {
                edge[key2].add(new Node(key1, -2));
                edge[key2].add(new Node(key1 + 1, -1));
            } else if (isLast[key1]) {
                edge[key2].add(new Node(key1, -2));
                edge[key2].add(new Node(key1 - 1, -1));
            } else {
                edge[key2].add(new Node(key1, -2));
                edge[key2].add(new Node(key1 + 1, -1));
                edge[key2].add(new Node(key1 - 1, -1));
            }
        }
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int T = Integer.parseInt(st.nextToken());
            int U1 = Integer.parseInt(st.nextToken());
            int U2 = Integer.parseInt(st.nextToken());
            int V1 = Integer.parseInt(st.nextToken());
            int V2 = Integer.parseInt(st.nextToken());
            int start = U1 * 100 + U2;
            int end = V1 * 100 + V2;
            fill(dist, Integer.MAX_VALUE);
            dijkstra(start, T);
            sb.append(dist[end])
                    .append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void dijkstra(int start, int T) {
        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        dist[start] = 0;
        pq.offer(new Node(start, 0));
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int now = node.v;
            int nowCost = node.cost;
            if (dist[now] < nowCost) {
                continue;
            }
            for (int i = 0; i < edge[now].size(); i++) {
                Node nextNode = edge[now].get(i);
                int next = nextNode.v;
                int nextCost = nextNode.cost;
                if (nextCost == -1) {  // 환승해서 갈아타는 경로인 경우
                    nextCost = T + 1;
                } else if (nextCost == -2) {  // 환승역이 유일한 역인 경우
                    nextCost = T;
                }
                if (dist[next] > nowCost + nextCost) {
                    dist[next] = nowCost + nextCost;
                    pq.offer(new Node(next, dist[next]));
                }
            }
        }
    }
}

class Node {
    int v;
    int cost;

    public Node(int v, int cost) {
        this.v = v;
        this.cost = cost;
    }
}