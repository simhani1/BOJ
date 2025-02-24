import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static boolean[] inDegree;

    public static void main(String[] args) throws Exception {
        /* input */
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        inDegree = new boolean[N + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            if (e < s) {
                for (int j = e; j < s; j++) {
                    inDegree[j] = true;
                }
            }
        }
        /* solve */
        for (int i = 1; i <= N; i++) {
            boolean flag = true;
            if (N % i == 0) {
                for (int j = i; j <= N; j += i) {
                    if (inDegree[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    System.out.println(N / i);
                    return;
                }
            }
        }
    }

}