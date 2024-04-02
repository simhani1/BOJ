import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 import java.util.Arrays;
 import java.util.Stack;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N, cnt;
    private static int[] arr;
    private static boolean[] visited;
    private static boolean[] finished;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());
            arr = new int[N + 1];
            visited = new boolean[N + 1];
            finished = new boolean[N + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
            cnt = 0;
            for (int i = 1; i <= N; i++) {
                if (!finished[i]) {
                    dfs(i);
                }
            }
            sb.append(N - cnt).append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void dfs(int idx) {
        if (finished[idx]) {
            return;
        }
        if (visited[idx]) {
            finished[idx] = true;
            cnt++;
        }
        visited[idx] = true;
        dfs(arr[idx]);
        finished[idx] = true;
        visited[idx] = false;
    }
}