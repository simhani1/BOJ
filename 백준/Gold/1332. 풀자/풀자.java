import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, V, ans;
    private static int[] arr;
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            min = Math.min(min, arr[i]);
            max = Math.max(max, arr[i]);
        }
        ans = N;
        if (max - min >= V) {
            dfs(0, Integer.MAX_VALUE, Integer.MIN_VALUE, 1);
        }
        System.out.println(ans);
    }

    private static void dfs(int idx, int min, int max, int cnt) {
        if (idx >= N || cnt >= ans) {
            return;
        }
        min = Math.min(min, arr[idx]);
        max = Math.max(max, arr[idx]);
        if (max - min >= V) {
            ans = Math.min(ans, cnt);
            return;
        }
        dfs(idx + 2, min, max, cnt + 1);
        dfs(idx + 1, min, max, cnt + 1);
    }

}