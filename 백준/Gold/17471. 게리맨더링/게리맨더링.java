import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, ans = Integer.MAX_VALUE;
    private static List<Integer>[] edge;
    private static int[] population;
    private static int[] teamColor;
    private static boolean[] include;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        population = new int[N + 1];
        edge = new ArrayList[N + 1];
        include = new boolean[N + 1];
        teamColor = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            edge[i] = new ArrayList<>();
            population[i] = Integer.parseInt(st.nextToken());
        }
        for (int from = 1; from <= N; from++) {
            st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            for (int j = 0; j < cnt; j++) {
                int to = Integer.parseInt(st.nextToken());
                edge[from].add(to);
                edge[to].add(from);
            }
        }
        solve(1, 0);
        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }

    private static void solve(int idx, int depth) {
        isSeperated();
        for (int i = idx; i <= N; i++) {
            if (!include[i]) {
                include[i] = true;
                solve(i + 1, depth + 1);
                include[i] = false;
            }
        }
    }

    private static void isSeperated() {
        /* 정확히 두 그룹으로 나뉘는지 확인 */
        int color = 0;
        visited = new boolean[N + 1];
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i, ++color);
            }
        }
        /* 두 그룹으로 나눠진 경우 */
        if (color == 2) {
            int stdColor = teamColor[1];
            int sumA = population[1], sumB = 0;
            for (int i = 2; i <= N; i++) {
                if (teamColor[i] != stdColor) {
                    sumB += population[i];
                } else {
                    sumA += population[i];
                }
            }
            ans = Math.min(ans, Math.abs(sumA - sumB));
        }
    }

    private static void dfs(int now, int color) {
        visited[now] = true;
        teamColor[now] = color;
        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now].get(i);
            if (visited[next]) {
                continue;
            }
            /* 같은 그룹인 경우 */
            if (include[now] == include[next]) {
                dfs(next, color);
            }
        }
    }
}