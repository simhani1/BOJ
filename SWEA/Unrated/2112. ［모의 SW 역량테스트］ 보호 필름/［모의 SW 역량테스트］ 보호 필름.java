import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, D, W, K, ans;
    private static boolean[] visited;
    private static int[] arrA;
    private static int[] arrB;
    private static final int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            D = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            int[][] arr = new int[D + 1][W + 1];
            visited = new boolean[D + 1];
            arrA = new int[W + 1];
            arrB = new int[W + 1];
            Arrays.fill(arrB, 1);
            for (int i = 0; i < D; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < W; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            if (K == 1) {
                ans = 0;
            } else {
                ans = INF;
                for (int i = 0; i <= D; i++) {
                    dfs(arr, 0, 0, i);
                    if (ans != INF) {
                        break;
                    }
                }   
            }
            sb.append("#").append(t).append(" ").append(ans).append("\n");
        }
        System.out.println(sb.toString());
    }

    private static void dfs(int[][] arr, int idx, int cnt, int goal) {
        /* 목표로 하는 약품 투입 횟수 */
        if (cnt == goal) {
            /* 정답이 되는지 검사 */
            for (int j = 0; j < W; j++) {
                int std = arr[0][j];
                int pSum = 1;
                boolean flag = false;
                for (int i = 1; i < D; i++) {
                    if (std == arr[i][j]) {
                        pSum++;
                        if (pSum >= K) {
                            flag = true;
                            break;
                        }
                    } else {
                        pSum = 1;
                        std = arr[i][j];
                    }
                }
                if (!flag) {
                    return;
                }
            }
            /* 정답이 가능한 경우 */
            ans = Math.min(ans, cnt);
            return;
        }
        /* 정답이 불가능하면 약품 투입 */
        for (int i = idx; i < D; i++) {
            if (!visited[i]) {
                visited[i] = true;
                int[] tmp = arr[i];
                arr[i] = arrA;
                dfs(arr, i + 1, cnt + 1, goal);
                arr[i] = arrB;
                dfs(arr, i + 1, cnt + 1, goal);
                arr[i] = tmp;
                visited[i] = false;
            }
        }
    }
}