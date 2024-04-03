import java.awt.image.AreaAveragingScaleFilter;
 import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 import java.util.*;


 public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[] inDegree;
     private static List<Integer>[] edge;
    private static PriorityQueue<Node> pq = new PriorityQueue<Node>((o1, o2) -> Integer.compare(o1.num, o2.num));

    static class Node {
        int num;

        public Node(int num) {
            this.num = num;
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        edge = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) {
            edge[i] = new ArrayList<>();
        }
        inDegree = new int[N + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            edge[A].add(B);
            inDegree[B]++;
        }
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) {
                pq.offer(new Node(i));
            }
        }
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int num = node.num;
            sb.append(num).append(" ");
            for (int next : edge[num]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    pq.offer(new Node(next));
                }
            }
        }
        System.out.println(sb.toString());
    }
}