import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int T, N;
    static int[] parent;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            parent = new int[N + 1];
            for (int i = 0; i <= N; i++) {
                parent[i] = i;
            }
            for (int i = 0; i < N - 1; i++) {
                st = new StringTokenizer(br.readLine());
                int A = Integer.parseInt(st.nextToken());
                int B = Integer.parseInt(st.nextToken());
                parent[B] = A;
            }
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            sb.append(lca(A, B)).append("\n");
        }
        System.out.println(sb);
    }

    private static int lca(int a, int b) {
        boolean[] visited = new boolean[N + 1];
        visited[a] = true;
        while (a != parent[a]) {
            a = parent[a];
            visited[a] = true;
        }
        while (!visited[b]) {
            b = parent[b];
        }
        return b;
    }
}