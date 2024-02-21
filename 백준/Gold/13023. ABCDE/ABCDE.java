import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, ans;
    private static List<Integer>[] arr;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            arr[A].add(B);
            arr[B].add(A);
        }
        ans = 0;
        for (int i = 0; i < N; i++) {
            if (ans == 0) {
                dfs(i, 1);
            }
        }
        System.out.println(ans);
    }

    private static void dfs(int now, int cnt) {
        if (cnt == 5) {
            ans = 1;
            return;
        }
        visited[now] = true;
        for (int next : arr[now]) {
            if (!visited[next]) {
                dfs(next, cnt + 1);
            }
        }
        visited[now] = false;
    }
}