import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, R, M, K;
    static String[] plan;
    static double[][] arr1, arr2;
    static Map<String, Integer> map = new HashMap<>();
    static final int INF = 987654321;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr1 = new double[N + 1][N + 1];
        arr2 = new double[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            String name = st.nextToken();
            map.put(name, i);
            Arrays.fill(arr1[i], INF);
            Arrays.fill(arr2[i], INF);
        }
        M = Integer.parseInt(br.readLine());
        plan = new String[M];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            plan[i] = st.nextToken();
        }
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            String type = st.nextToken();
            int a = map.get(st.nextToken());
            int b = map.get(st.nextToken());
            double c = Double.parseDouble(st.nextToken());
            arr1[a][b] = arr1[b][a] = Math.min(arr1[a][b], c);
            if (isFree(type)) {
                arr2[a][b] = arr2[b][a] = Math.min(arr2[a][b], 0);
            } else if (isHalf(type)) {
                arr2[a][b] = arr2[b][a] = Math.min(arr2[a][b], c / 2.0);
            } else {
                arr2[a][b] = arr2[b][a] = Math.min(arr2[a][b], c);
            }
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i == k || k == j || i == j) {
                        continue;
                    }
                    arr1[i][j] = Math.min(arr1[i][j], arr1[i][k] + arr1[k][j]);
                    arr2[i][j] = Math.min(arr2[i][j], arr2[i][k] + arr2[k][j]);
                }
            }
        }
        double ans1 = 0, ans2 = R;
        for (int i = 1; i < M; i++) {
            int from = map.get(plan[i - 1]);
            int to = map.get(plan[i]);
            ans1 += arr1[from][to];
            ans2 += arr2[from][to];
        }
        System.out.println(ans1 > ans2 ? "Yes" : "No");
    }

    private static boolean isFree(String type) {
        return "Mugunghwa".equals(type) || "ITX-Saemaeul".equals(type) || "ITX-Cheongchun".equals(type);
    }

    private static boolean isHalf(String type) {
        return "S-Train".equals(type) || "V-Train".equals(type);
    }
}