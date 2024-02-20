import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static List<Integer>[] arr;
    private static int indegree[];
    private static Queue<Integer> q = new ArrayDeque<>();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new ArrayList[N + 1];
        indegree = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            arr[A].add(B);
            indegree[B]++;
        }
        solve();
        System.out.println(sb.toString());
    }

    private static void solve() {
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append(" ");
            for (int i = 0; i < arr[now].size(); i++) {
                indegree[arr[now].get(i)]--;
                if (indegree[arr[now].get(i)] == 0) {
                    q.offer(arr[now].get(i));
                }
            }
        }
    }
}