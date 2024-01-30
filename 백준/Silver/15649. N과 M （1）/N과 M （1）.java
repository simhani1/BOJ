import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[] arr;
    private static boolean[] visited = new boolean[10];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[M + 1];
        go(0);
        System.out.println(sb.toString());
    }

    private static void go(int idx) {
        if (idx == M) {
            for (int i = 0; i < M; i++) {
                sb.append(arr[i])
                        .append(" ");
            }
            sb.append("\n");
            return;
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                arr[idx] = i;
                go(idx + 1);
                visited[i] = false;
                arr[idx] = 0;
            }
        }
    }
}