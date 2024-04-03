import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


 public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N, K;
    private static int[] inDegree, time, result;
     private static List<Integer>[] edge;
     private static Queue<Integer> q;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            inDegree = new int[N + 1];
            time = new int[N + 1];
            result = new int[N + 1];
            edge = new ArrayList[N + 1];
            q = new ArrayDeque<>();
            for (int i = 1; i <= N; i++) {
                edge[i] = new ArrayList<>();
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                time[i] = Integer.parseInt(st.nextToken());
            }
            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int X = Integer.parseInt(st.nextToken());
                int Y = Integer.parseInt(st.nextToken());
                inDegree[Y]++;
                edge[X].add(Y);
            }
            int W = Integer.parseInt(br.readLine());
            /* 위상정렬 */
            for (int i = 1; i <= N; i++) {
                if (inDegree[i] == 0) {
                    q.offer(i);
                }
                result[i] = time[i];
            }
            while (!q.isEmpty()) {
                int now = q.poll();
                for (int next : edge[now]) {
                    result[next] = Math.max(result[next], result[now] + time[next]);
                    inDegree[next]--;
                    if (inDegree[next] == 0) {
                        q.offer(next);
                    }
                }
            }
            sb.append(result[W]).append("\n");
        }
        System.out.println(sb);
    }
}