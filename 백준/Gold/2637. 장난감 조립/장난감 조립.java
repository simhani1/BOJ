import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static int[] inDegree;
    static int[] arr;
    static List<Node>[] edge;

    static class Node {
        int num;
        int cnt;

        public Node(int num, int cnt) {
            this.num = num;
            this.cnt = cnt;
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        inDegree = new int[N + 1];
        arr = new int[N + 1];
        edge = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            edge[i] = new ArrayList<>();
        }
        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            edge[a].add(new Node(b, c));
            inDegree[b]++;
        }
        arr[N] = 1;
        Queue<Integer> ans = new PriorityQueue<>();
        Queue<Integer> pq = new PriorityQueue<>();
        pq.offer(N);
        while (!pq.isEmpty()) {
            int now = pq.poll();
            if (edge[now].isEmpty()) {
                ans.offer(now);
                continue;
            }
            for (Node node : edge[now]) {
                int next = node.num;
                int cnt = node.cnt;
                arr[next] += (arr[now] * cnt);
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    pq.offer(next);
                }
            }
        }
        while (!ans.isEmpty()) {
            int num = ans.poll();
            sb.append(num).append(" ").append(arr[num]).append("\n");
        }
        System.out.println(sb);
    }
}