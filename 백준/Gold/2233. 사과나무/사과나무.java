import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, X, Y;
    private static int[] parent;
    private static int[] arr;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        parent = new int[N + 1];
        visited = new boolean[N + 1];
        String str = br.readLine();
        M = 2 * N;
        arr = new int[M + 1];
        for (int i = 1; i <= M; i++) {
            arr[i] = str.charAt(i - 1) - '0';
        }
        st = new StringTokenizer(br.readLine());
        X = Integer.parseInt(st.nextToken());
        Y = Integer.parseInt(st.nextToken());
        /* marking */
        dfs(1, 1, 0);
        /* find common ancient */
        parent[0] = -1;
        int target = lca();
        for (int i = 1; i <= M; i++) {
            if (arr[i] == target) {
                sb.append(i).append(" ");
            }
        }
        System.out.println(sb);
    }

    private static int lca() {
        for (int i = arr[X]; i != -1; i = parent[i]) {
            for (int j = arr[Y]; j != -1; j = parent[j]) {
                if (i == j) {
                    return i;
                }
            }
        }
        return 0;
    }

    private static void dfs(int idx, int now, int par) {
        if (idx == M + 1) {
            return;
        }
        if (arr[idx] == 0) {
            parent[now] = par;
            arr[idx] = now;
            dfs(idx + 1, now + 1, now);
        } else {
            arr[idx] = par;
            dfs(idx + 1, now, parent[par]);
        }
    }
}